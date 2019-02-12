#include<iostream>
#include<algorithm>


using namespace std;

long long ncr(int n,int r) {
  long long p = 1;
  long long k = 1;

  if(n-r<r) r = n-r;

  if(r!=0) {
   while(r) {
    p*=n;
    k*=r;
    int m = __gcd(p,k);

    p/=m;
    k/=m;

    n--;
    r--;
   }
  } else return 1;

  return p;
}

int main() {
  cout<<ncr(99,25)<<endl;
}