#include<iostream>
using namespace std;

long long x[100000],y[100000],k,n,a=0,b=2000000000;

int check(long long c){
	long long s=0;
	for(int i=0;i<n;i++){
		if(x[i]*c>y[i])
			s+=x[i]*c-y[i];

		if(s>k)
		return false ;

	}	
	return true;
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>x[i];

	for(int i=0;i<n;i++)
		cin>>y[i];

	while(a<b)
	{
		long long c=(a+b+1)/2;
		if(check(c))
			a=c;
		else
		b=c-1;
	}	
	cout<<a<<endl;
	return 0;
}
