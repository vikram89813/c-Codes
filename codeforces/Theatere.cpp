#include<iostream>
#include<math.h>

using namespace std;

int main()
{
  long double m,n,a;
  cin>>m>>n>>a;
  cout<<ceil(m/a) * ceil(n/a)<<endl;
  return 0;
}
