#include<iostream>

using namespace std;

string s;
int a,n;

int main()
{
	cin>>s;
    s="00"+s;
    n=s.size();

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				a=(s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
                cout<<a<<endl;
				if(a%8==0)
                {
                  cout<<"YES"<<endl<<a;
                  return 0;
                }
			}}}

	cout<<"NO";
    return 0;
}
