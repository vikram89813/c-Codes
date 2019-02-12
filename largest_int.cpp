#include<bits/stdc++.h>
using namespace std;

/*void fun(vector<int> &arr) {
    sort(arr.begin(),arr.end(),[] (int a,int b) {
        int s1,s2,ms1,ms2;
        s1=s2 = 0;
        int a1 = a;
        int b2 = b;
        while(a) {
            s1++;
            ms1 = a%10;
            a = a/10;
        }

        while(b) {
            s2++;
            ms2 = b%10;
            b/=10;
        }
       // cout<<a<<" "<<b<<endl;
        if(ms1 != ms2) return ms1>ms2;
        else {
            string s1 = to_string(a1);
            string s2 = to_string(b2);
            //cout<<a<<" "<<b<<endl;

            string t1 = s1+s2;
            string t2 = s2+s1;

            int t11 = stoi(t1);
            int t22 = stoi(t2);

            //cout<<t11<<" "<<t22<<endl;

            return (t11>t22?true:false);

        }
    });

    for(auto i : arr) cout<<i;
    cout<<endl;
}*/

int main() {
    vector<int> arr = {1, 34, 3, 98, 9, 76, 45, 4};
    sort(arr.begin(),arr.end(),[](int a,int b){
        string s1 = to_string(a);
        string s2 = to_string(b);

        string s3 = s1+s2;
        string s4 = s2+s1;

        return (s3>s4 ? true: false);
    });

    for(auto i : arr) cout<<i;
    cout<<endl;
    //fun(arr);
}