#include<iostream>

int N;
int ans;
int arr1[500005]
int arr2[500005]
int arr3[500005]
bool h1[500005]
bool h2[500005]
bool h3[500005]

void init() {
  for(int i=0;i<N;i++) {
    h1[i] = h2[i] = h3[i] = false;
  }
}

int main() {
  cin>>N;
  init();
  for(int i=0;i<N;i++) {cin>>arr1[i];h1[arr1[i]] = true;}
  for(int i=0;i<N;i++) {cin>>arr2[i];h2[arr2[i]] = true;}
  for(int i=0;i<N;i++) {cin>>arr3[i];h3[arr3[i]] = true;}
}
