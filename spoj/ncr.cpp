#include<iostream>

using namespace std;

long long ncr(int n,int k) {
  long long res = 1;
  if(k > n-k) k = n-k;

  for(int i=0;i<k;i++) {
    res *= (n-i);
    res/= (i+1);
  }
  return res;
}

int main() {
  int a,b;
  cin>>a>>b;
  cout<<ncr(a,b)<<endl;
  return 0;
}
