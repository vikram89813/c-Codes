#include<iostream>
#include<vector>

using namespace std;

void sort012(vector<int> &arr,int s) {
  int l=0;
  int m =0;
  int h= s-1;

  while(m<=h) {
    switch(arr[m]) {
      case 0:
        swap(arr[l++],arr[m++]);
        break;
      case 1:
        m++;
        break;
      case 2:
        swap(arr[m],arr[h--]);
        break;
    }
  }
}

int main() {
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = arr.size();
    sort012(arr, arr_size);
    printf("array after segregation: \n");
    for(auto i : arr) cout<< i<<" ";
    cout<<endl;
    return 0;
}
