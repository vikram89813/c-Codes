#include<iostream>

using namespace std;

long long arr[50001];
int N;

long long cal() {
    int i = 0, l = 0, r = 0;
    int count = 0;
    while (i < N - 1) {
        while (arr[i] < arr[i + 1] && i < N-1) i++,l++;
        while (arr[i] > arr[i + 1] && i < N-1) i++,r++;
        count += l*r;
        l = 0; r = 0;
    }
    return count;
}

int main() {
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    cin>>N;
    for(int i=0;i<N;i++) scanf("%lld",&arr[i]);
    cout<<"#"<<t<<" "<<cal()<<endl;
  }
}
