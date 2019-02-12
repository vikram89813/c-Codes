#include<iostream>

using namespace std;

long long catalan(int n,int k) {
  long long res = 1;
  if(k > n-k) k = n-k;

  for(int i=0;i<k;i++) {
    res *= (n-i);
    res/= (i+1);
  }
  return res;
}

int main() {
  for(int i=0;i<10;i++) {
    cout<<"catalan no for "<<i<<" : "<<(catalan(2*i,i))/(i+1)<<endl;
  }
  return 0;
}
