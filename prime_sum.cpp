#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>

using namespace std;

vector<int> sieve(int n) {
        vector<int> ans;
        if (n < 2) {
            return ans;
        }

        int arr[n + 1];
        memset(arr, 0, sizeof(arr));
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 0) {
                ans.push_back(i);
                for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
            }
        }
        return ans;
    }


int main()
{
  int n = 4;
  vector<int> prime_ = sieve(n);
  sort(prime_.begin(),prime_.end());
  for(int i = 0;i<prime_.size();i++)
  {
    int a = prime_[i];
    int b = n-a;
    if(binary_search(prime_.begin(),prime_.end(),b)) {cout<<a<<","<<b;break;}
  }
  cout<<endl;
  return 0;
}
