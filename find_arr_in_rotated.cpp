#include<iostream>

using namespace std;



int main() {
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int i = search_(arr, 0, n-1, key);

    if (i != -1)
    cout << "Index: " << i << endl;
    else
    cout << "Key not found";
}
