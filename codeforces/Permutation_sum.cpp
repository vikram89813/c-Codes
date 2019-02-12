#include<stdio.h>

int ans[]={1,18,1800,670320,734832000,890786230,695720788,150347555};

int main()
{
	int n;
	scanf("%d",&n);
	if(n%2)
      printf("%d\n",ans[n/2]);
	else
      printf("0\n");
    return 0;
}
