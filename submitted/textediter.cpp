#define size 700
#define NULL 0

enum COMMAND {
	CMD_MOVE_UP = 0,
	CMD_MOVE_DOWN = 1,
	CMD_MOVE_LEFT = 2,
	CMD_MOVE_RIGHT = 3,
	CMD_INPUT_CHAR = 4,
	CMD_INPUT_NEWLINE = 5,
	CMD_GET_CHAR = 6,
	CMD_END_TC = 9
};

enum OMMAND {
	UP,            
	DOWN,
    LEFT,
    RIGHT,
};

struct row
{
   char s[size];
   int l;	
};

row Mat[size];
int c,r,editorSize,activero;
row *pa[size];


void init(int n)
{
	c=r=0;
	//editorSize = n;
	for(int i=0;i<size;i++)
	{
		Mat[i].l = 0;
		pa[i] = NULL;
	}
	pa[0]=&Mat[0];
	activero = 1;
}

void input_char(char in_char)
{
	 //cout<<in_char;
	 if(c<pa[r]->l)
	 {
	 	//cout<<in_char;
	 	for(int i=pa[r]->l-1;i>=c;i--)
	 	 {
	 	   pa[r]->s[i+1] = pa[r]->s[i];		
		 }
	 }
	
	 //cout<<r<<c;

	 pa[r]->s[c] = in_char;
	 //cout<<pa[r]->s[c]<<Mat[0].s[0];
     pa[r]->l++;
	 c++;
}

void input_newline()
{
	int y =  activero;
	//pa[activero]  = &Mat[activero];
	
	 for (y;y>r+1;y--)
        pa[y] = pa[y-1];
	
	pa[y] = &Mat[activero];
	pa[y]->l=0;
		    
	 if(c<pa[r]->l)
	 {
		int i=0;
		int j=c;
		while(j<pa[r]->l)
		{
			pa[y]->s[i]=pa[r]->s[j];
			//pa[r]->s[j] = '\0';
			pa[y]->l++;
			j++;
			i++;
		}
	 }
	 pa[r]->l=c;
	 c=0;
	 r++;
	 activero++;
	 //cout<<r<<c;
}

void move_cursor(int direction) // 0: Up, 1: Down, 2: Left, 3: Right
{
	 switch(direction)
	 {
	 	case UP:
	 		if (r == 0)
			   break;
			r--;
			if (c>pa[r]->l)
			   c=pa[r]->l;	   
	 		break;
	 		
	 	case DOWN:
	 		if (r==activero-1)
			   break;
			r++;
			if (c>pa[r]->l)
			   c=pa[r]->l;
			    
	 		break;
		case LEFT:
			if (r==0 && c==0)
			   break;
			     
			if (c==0)
			   {
			   	 if (r>0)
			        {
				      r--;
				      c = pa[r]->l;
				    }
			   }
			else
			   c--; 
			       
	 		break;
	 		
		case RIGHT:
			if (r==activero-1 && c==pa[r]->l)
	 		   break;
		    if (c==pa[r]->l)
			   {
			   	 if(r<activero-1)
			       {
				     r++;
				     c= 0;	
				   }
			   }
			else
			   c++;   			 	 	
	 }
}

char get_char(int row, int column)
{
	//cout<<pa[row-1]->s[column-1];
	return pa[row-1]->s[column-1];	
}
