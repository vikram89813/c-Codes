#include<iostream>

using namespace std;

int main() {
  int N;
  long long R,t;
  cin>>N>>R;
  for(int i=0;i<N;i++) {
    cin>>t;
    if(t < R) cout<<"Bad boi"<<endl;
    else cout<<"Good boi"<<endl;
  }
}
