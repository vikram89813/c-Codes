struct node{
	node* child;
	int count; //contains count of all the child directories
	int totalcount; //contains total count of all the descendant directories
	node* parent;
	node* next;
	char name[20];
}
node* root;
node arr[20005];
int idx;
node* current; //current directory

//static allocation of nodes
void allocatenode(node* temp)
{ 
temp=&arr[idx];
idx++;
}

int strcmp_n(char* a,char* b,int n)
// does strcmp upto length n 
// return postive if a[0..n-1] > b[0..n-1]
// return negative if a[0..n-1] < b[0..n-1]
// return zero if a[0...n-1] = b[0...n-1]



//The child directories are stored as a sorted list (ascending order of name) using insertion sort 


void init()
{   
idx = 0;
allocatenode(root);
=> initiliase pointers such as parent and child to null
=> set counts to 0
}

void cmd_mkdir(char mKeyword[]){
    node* new;
	allocatenode(new);
	set count,name and other values of the new node 
	
	node* child1 = current->child;
	
	=> check if child1 is null i.e. no child exists for the current directory so just assign current->child to new
	
	=> else process the elements of linked list to find the position of this new node and insert it at the place.
	
	=>increase count and totalcount of current node by 1 
	
	=>use parent pointers to increase the totalcount of parent nodes recursively by 1

 
}

void cmd_cd(char mKeyword[])
{
    node* child1 = current->child;
	=> if child1 is null i.e. no child exists for the current directory then return 
	
	=>if mKeyword is * then current = current->child 
	
	=> let n be the length of mkeyword (not considering * at the end)
	
	=> scan through the linked list of child nodes by matching the mkeyword(prefix) given and when we find a match(strcmp_n == 0) then it will be lexicographically smallest match . 
	We set current to that node then return
	
	=> while scanning if the n-prefix of name of node being scan is larger(using strcmp_n) than mKeyword, then it means that no other node will match the mKeyword given therefore we return  
}

int cmd_rm(char mKeyword[])
{
    int deletecount = 0; // contains child directories deleted 
	int deletetotalcount = 0; //contains total directories deleted(child and descendant directories) 
	
	=>if mKeyword is * then 
	current->child = NULL and deletetotalcount = current->totalcount 
	set current->totalcount =0;
	current->count =0;
	recursively decrease totalcount [totalcount = totalcount - deletetotalcount] of parent directories using parent pointers 
	return deletetotalcount
	
	
	
	=> else 
	scan through the child nodes list and for each node that matches the prefix mKeyword 
         -deletecount ++
         -deletetotalcount = deletecount + (totalcount of matched node)
		 -remove the node from the linked list
    
	while scanning if the n-prefix of name of node being scan is larger(using strcmp_n) than mKeyword, then it means that no other node will match the mKeyword given therefore we stop

	current->count = current->count - deletecount 
	current->totalcount = current->totalcount - deletetotalcount
	recursively decrease totalcount [totalcount = totalcount - deletetotalcount] of parent directories using parent pointers 
	return deletetotalcount
}


int cmd_find(char mKeyword[])
{
	do a recursive search of all the descendant directories and for each directory that matches the mKeyword prefix increase count by 1 and return final count. 
}



