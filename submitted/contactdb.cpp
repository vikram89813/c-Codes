#define size 50000
#define long_max  1000000000003

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

struct rec
{
   char name[20];
   char number[20];	
   char birthday[20];	
   char email[20];	
   char memo[20];
   int valid;
};

rec table[size];
int hash[5][size];
int chain[5][size];
int row;

typedef enum
{
	CMD_INIT,
	CMD_ADD,
	CMD_DELETE,
	CMD_CHANGE,
	CMD_SEARCH
} COMMAND;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int Hash(char *s)
{/*
    unsigned long int h=5381;
    while(*s)
	{
	   h = ((h << 5) + h + *s)%size;
	   s++;	
	}                                                               >> 393ms
	//cout <<">>>>>h"<< h%size<<endl;
	return h%size;
	
   */
	//long long long_max  = 1000000000003LL;
    long long hash_val = 0;
    int i = 0;
    while (s[i] != '\0'){
        hash_val = (hash_val * 31) + s[i];
 
        hash_val = hash_val % long_max;                             //>> 387
        i++;
    }
    //cout <<">>>>>h"<< hash_val%size<<endl;

    return hash_val%size;  
/*	unsigned int h=131;
    while(*s)
	{
	   h = (h << 5) + *s;
	   s++;	                                                          >> 671
	}	   
	//cout <<">>>>>h"<< h%size<<endl;
	return h%size;   */
}

void mystrcpy(char *d,char *s)
{
	while(*s)
	{
		*d=*s;
		d++;
		s++;
	}
	*d='\0';
}

int mystrlen(char *s)
{
	int i=0;
	while(*s++)
	{
       i++;
	}
	return i;
}

int mystrcmp(char *t, char *s)
{
	if (mystrlen(t)!=mystrlen(s))
	   return 0;
     
	while(*s)
	{
	   if (*s!=*t)
	     return 0;	
       t++;
       s++;
	}
	return 1;
}

void InitDB()
{   
	   for(int i=0;i<size;i++)
	   {
	   	  hash[NAME][i] = chain[NAME][i] = -1;
	   	  hash[NUMBER][i] = chain[NUMBER][i] = -1;
	   	  hash[BIRTHDAY][i] = chain[BIRTHDAY][i] = -1;
	   	  hash[EMAIL][i] = chain[EMAIL][i] = -1;
	   	  hash[MEMO][i] = chain[MEMO][i] = -1;
	   	  table[i].valid = 0;
	   }
    row=0;            //mistake 1
}

void insert(int key,int index,int FIELD)
{
      int temp;
	  if(hash[FIELD][key] == -1)
	  {
		   hash[FIELD][key] = index;
	  }
	  else
	  {
		   temp =  hash[FIELD][key];
		   hash[FIELD][key] = index;
		   chain[FIELD][index] = temp;
	  }
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	   mystrcpy(table[row].name,name);
	   mystrcpy(table[row].number,number);
	   mystrcpy(table[row].birthday,birthday);
	   mystrcpy(table[row].email,email);
	   mystrcpy(table[row].memo,memo);
	   table[row].valid = 1;
	   
	   int key=Hash(name);
	   insert(key,row,NAME);
	   key=Hash(number);
  	   insert(key,row,1);
	   key=Hash(birthday);
  	   insert(key,row,2);
	   key=Hash(email);
  	   insert(key,row,3);
	   key=Hash(memo);
  	   insert(key,row,4);
	   
	   row++;
}

int Delete(FIELD field, char* str)
{
	 int key = Hash(str);
	 int r =0;
	 int index =  hash[field][key];
	 int preindex = -1;               //mistake2
	 
   if (index==-1)     //no matching records
	  return r;

   while(index!=-1)
   {
     if (table[index].valid && mystrcmp(table[index].name+field*20,str))
     {
     	table[index].valid=0;
     	r++;
     	
     	if(preindex==-1)
     	 {
     	 	hash[field][key] = chain[field][index];          //msitake 4
     	 	chain[field][index] = -1;
            index = hash[field][key];                         //mistake 3
     	 	
         }
        else
		 {
		    chain[field][preindex] = chain[field][index];
			chain[field][index] = -1;	
            index = chain[field][preindex]; 
	     }

	 }
	 else
	 {
	 	preindex = index;
	 	index = chain[field][index];
     }
   }
   
   return r;
}

void deleteindx(int key,int index,int F)
{
	int cur =  hash[F][key];
	int pre = -1;

	while(cur!=index)
    {
		 pre = cur;
		 cur = chain[F][pre];
	}
	
	if(pre==-1)
	{
		hash[F][key]=chain[F][index];
		chain[F][index]=-1;
	}
	else
	 {
	    chain[F][pre]=chain[F][cur];
	    chain[F][cur]= -1;	
	 }
	   
}                    

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
    int key = Hash(str);
    int r =0,ni=-1;
	int index =  hash[field][key];
	
	if (index==-1)     //no matching records
	  return r;
	
	while(index!=-1)
	{
	  ni =  chain[field][index];                             //mistake
	  if (table[index].valid && mystrcmp(table[index].name+field*20,str))
	    {
	    	r++;
			key = Hash(table[index].name+changefield*20);
			deleteindx(key,index,changefield);
			key = Hash(changestr);
			insert(key,index,changefield);
			mystrcpy(table[index].name+changefield*20,changestr);
    	}
		index =  ni;
		
    }
	
	return r;
}

RESULT Search(FIELD field, char* str, FIELD returnfield)
{
	int key = Hash(str);
    RESULT r;
    r.count=0;
    r.str[0]='\0';
	int index =  hash[field][key];
	
	if (index==-1)
	   return r;
	
	while(index!=-1) 
	{
	   if (table[index].valid && mystrcmp(table[index].name+field*20,str))
	    {
	    	r.count++;
	    	//if(r.count==1)
	    	  mystrcpy(r.str,table[index].name+returnfield*20);  
	    }
	    index=chain[field][index];
    }
    
    /*if (r.count!=1)
	   r.str[0]='\0'; */
	   
	return r;   
	   
}


