#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> arr3;
int N;

void cal() {
  //sort the arrays.
  sort(arr1.begin(),arr1.end());
  sort(arr2.begin(),arr2.end());
  sort(arr3.begin(),arr3.end());

  long long ans = INT_MAX;

  for(auto i : arr1) {
    // find first element greater than the current element.
    int idx1 = lower_bound(arr2.begin(),arr2.end(),i) - arr2.begin();
    int idx2 = lower_bound(arr3.begin(),arr3.end(),i) - arr3.begin();
    int idx3 = N;
    int idx4 = N;
    if(idx1) idx3 = idx1-1;
    if(idx2) idx4 = idx2-1;

    long long t1,t2;

    // check if previous element in the arr2 or arr3 needs to be selected instead.
    if(idx3 != N) {
      if(abs(i-arr2[idx1]) < abs(i-arr2[idx3]))
        t1 = idx1;
      else t1 = idx3;
    } else t1 = idx1;

    if(idx4 != N) {
      if(abs(i-arr3[idx2]) < abs(i-arr3[idx4]))
        t2 = idx2;
      else t2 = idx4;
    } else t2 = idx2;

    // find the min and max of the triplet.
    vector<int> temp = {i,arr2[t1],arr3[t2]};
    auto range = minmax_element(temp.begin(),temp.end());

    // update the ans.
    if(abs(temp[range.second-temp.begin()]-temp[range.first-temp.begin()]) < ans)
      ans = abs(temp[range.second-temp.begin()]-temp[range.first-temp.begin()]);
  }
  cout<<ans<<endl;
}

int main() {
  int T;
  cin>>T;
  while(T--) {
    arr1.clear();
    arr2.clear();
    arr3.clear();
    cin>>N;
    for(int i=0;i<N;i++) {
      int t;
      cin>>t;
      arr1.push_back(t);
    }
    for(int i=0;i<N;i++) {
      int t;
      cin>>t;
      arr2.push_back(t);
    }
    for(int i=0;i<N;i++) {
      int t;
      cin>>t;
      arr3.push_back(t);
    }
    cal();
  }
  return 0;
}
