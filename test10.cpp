#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    int b,k;
    vector<int> arr;
    cin>>b>>k;
    for(int i=0;i<k;i++) {
        int t;
        cin>>t;
        arr.emplace_back(t);
    }

    long long ans = 0;
    static int j=0;
    for(int i=k;i>0;i--) {
        ans += pow(b,i-1) *arr[j++]; 
    }

    if(ans %2) cout<<"odd"<<endl;
    else cout<<"even"<<endl;
    return 0;
}