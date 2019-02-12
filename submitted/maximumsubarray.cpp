#include<iostream>

using namespace std;

int arr[200001];
int N;

int sol() {
  int max_ending_here = 0;
  int max_ = 0;
  for(int i=0;i<N;i++) {
    max_ending_here = max_ending_here + arr[i];
    if(max_ending_here<0) max_ending_here = 0;
    if(max_ending_here > max_) max_ = max_ending_here;
  }
  return max_;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input_max_subarray", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {  
      cin>>N;
      for(int i=0;i<N;i++) cin>>arr[i];
      cout<<"#"<<test_case<<" "<<sol()<<endl;
    }
    return 0;
}

