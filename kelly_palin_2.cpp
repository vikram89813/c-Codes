#include<iostream>

using namespace std;

char arr[11];
short hash_[25];

int main(int argc, char** argv)
{
    short T;
    cin>>T;
    short sum;
    for(short test_case = 1; test_case <= T; ++test_case)
    {
        sum=0;
        cin>>arr;
        for(short i=0;i<=26;i++) hash_[i]=0;
        short i=0;
        while(arr[i]) {
          hash_[arr[i]-'a']++;
          i++;
        }
        for(short i=0;i<26;i++) sum+=((hash_[i]*(hash_[i]+1))/2);
        cout<<"#"<<test_case<<" "<<sum<<endl;
    }
    return 0;
}

