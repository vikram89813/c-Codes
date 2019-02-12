#define MAX 100005

int arry[MAX];
int Farry[MAX];
int Fh;
int Fi;
int H;
int ah,track_sze;
int start,end;
int d =-1, cld=-1;          

void init(int track_size, int head){
	  H=head;
	  Fi=Fh=0;
	  track_sze = track_size+1;
	  end = -1;
	  start= track_size;
	  d=cld=-1;
	  for(int i=0;i<MAX;i++)
	  {
		  arry[i] = Farry[i]=-1;
	  }
}

void request(int track){
	
	Farry[Fi]=track;
	arry[track] = Fi;
	Fi++;
	
	if (track<start)
	   start =track;
	if (track>end)
	   end=track;	
}

int fcfs(){
	int track_no =-1;
	
	while(Farry[Fh]==-1)
	    Fh++;
	track_no = Farry[Fh];	
	Farry[Fh] = -1;
		
	arry[track_no] = -1;
	H = track_no;
	return track_no;
}

int sstf(){
	
	int track_no = -1;
	int l,r;
	l = r= H;
	
	while(l>=start && r<=end && arry[l]==-1 && arry[r]==-1)
	{
		l--;
		r++;
	}
	if(l<start)
	{
		while(r<=end && arry[r]==-1)
		   r++;
		track_no = r;   
	}
	else if(r>end)
	{
		while(l>=start && arry[l]==-1)
		   l--;
		track_no = l;   
	}
	
	if(track_no==-1)
	{
		if (arry[l]==-1)
		   track_no = r;
		else if (arry[r]==-1) 
		       track_no = l;
			 else
			   track_no = l;    
	}
	
	Farry[arry[track_no]]= -1;
	arry[track_no] = -1;
	H = track_no;
	return track_no;
}

int look(){
	int track_no = -1;
	int l = H;
	
	while(l>=start && l<=end && arry[l]==-1)               //this is will either move l or r add cases for both
	     l = l+d;
	
   if (l<start)
	   {
		  d=1;
		  l=H;
		  while (l<=end && arry[l]==-1)
	         l = l+d;
	   }  
	else if (l>end)
	   {
	      d=-1;
		  l=H;
		  while (l>=start && arry[l]==-1)
	         l = l+d;  	
	   }
	   
	if (arry[l]!=-1)
	   track_no = l;
	   
	Farry[arry[track_no]]= -1;
	arry[track_no] = -1;
	H = track_no;
	return track_no;
}

int clook(){
	int track_no = -1;
	int l = H;
	
	while(l>=start && arry[l]==-1)
	     l = l+cld;
	 
   if (l<start)
	   {
		  l=end;
		  while (l>H && arry[l]==-1)
	         l = l+cld;
	   }  

	if (arry[l]!=-1)
	   track_no = l;                           //mistake typo
	   
	Farry[arry[track_no]]= -1;
	arry[track_no] = -1;
	H = track_no;
	return track_no;
}
