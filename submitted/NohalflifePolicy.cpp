#include<iostream>

using namespace std;

int n,K;
int arr[200001];
int karr[200001];
int ans;
int max_;

void clear_() {
  n=K;0;
  ans = 200002;
  max_ = -1;
  for(int i =0;i<200001;i++) arr[i]=-1,karr[i]=-1;
}

bool check(int num) {
  int idx =0;
  bool res = false;
  bool status;
  int i =0;
  while(i<n && idx < K){
    int t = karr[idx];
    int u =i;
    status = false;
    int limit = i+t;
    if(limit > n) return false;
    for( ;u<limit;u++) {
      if(u<n) {
        if(arr[u] > num) {
          status = true;
          break;
        }
      }
    }

    if(!status) {
      if(idx == K-1) {
        res = true;
        break;
      }
      idx++;
      i=u;
     }
    else i = u+1;
  }
  return res;
}

void sol() {
  for(int i=0;i<n;i++) if(arr[i] > max_) max_ = arr[i];
  int start = 0;
  int end = max_;
  while(start<=end) {
    int mid = (start+end)/2;
    if(check(mid)) {
      if(mid<ans) ans = mid;
      end = mid-1;
    } else {
      start = mid+1;
    }
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input_half_life", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
      clear_();
      cin>>n>>K;
      for(int i=0;i<n;i++) cin>>arr[i];
      for(int i=0;i<K;i++) cin>>karr[i];
      //if(test_case == 3)
      sol();
      cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;
}

