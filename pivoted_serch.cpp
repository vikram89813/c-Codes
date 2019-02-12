#include<iostream>
#include<vector>

using namespace std;



int search_(vector<int> &arr,int l,int h,int k) {
  int idx = find_p(vector<int> &arr,int l,int h);
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = arr.size();
    int key = 6;
    int i = search_(arr, 0, n-1, key);
    if (i != -1)
      cout << "Index: " << i << endl;
    else
      cout << "Key not found";
    return 0;
}
