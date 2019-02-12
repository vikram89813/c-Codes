#include<iostream>
#include<vector>

using namespace std;

int find_helper(vector<int> &arr,int l,int h) {
  int i=l;
  int p = arr[h];
  for(auto j = l;j<h;j++) {
    if(arr[j] <= p) {
      swap(arr[i],arr[j]);
      i++;
    }
  }
  swap(arr[i],arr[h]);
  return i;
}

int find_p(vector<int> &arr,int l,int h) {
  srand(time(NULL));
  int random = l + rand() % (h - l);
  swap(arr[random],arr[h]);
  return find_helper(arr,l,h);
}

void quickSort(vector<int> &arr,int l,int h) {
  if(l<h) {
    int p = find_p(arr,l,h);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,h);
  }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
    return 0;
}
