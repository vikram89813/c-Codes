#include <iostream>
using namespace std;

int main()
{
  int n=0;
  cin>>n;
  for(int i=n;i>=1;i--)
  {
    if(n%i==0)
    {
      cout<<i<<" ";
      n=i;
    }
    //cout<<n<<endl;
  }
  return 0;
}
