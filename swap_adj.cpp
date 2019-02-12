#include<iostream>

using namespace std;

long long ans;
char arr1[100001];
char arr2[100001];
int arr3[100001];
int arr4[100001];
int N;
int c_a1;
int c_a2;
int c_b1;
int c_b2;
long long bit[100002];
int hash_[100001];

/*void adjSwap(char src[], char dst[]) {
    ans = 0;
	for (int cur = 0; cur < n; ++cur) {
		if (src[cur] == dst[cur]) continue;
		int ct = cur+1;
		for (; src[ct] != dst[cur] && ct < n; ++ct);
		for (; ct != cur; --ct) {
			swap(src[ct], src[ct - 1]);
            ans++;
		}
	}
}*/

long long get_s(int idx) {
  long long s =0;
  while(idx > 0) {
    s+= bit[idx];
    idx-= idx & (-idx);
  }
  return s;
}

void update(int idx,int v) {
  while(idx <= N) {
    bit[idx]+=v;
    idx+= idx&(-idx);
  }
}

void adj_swap() {
  for(int i=0;i<100002;i++) bit[i] = 0;
  int b_start = c_a1+2;
  int a_start = 1;
  for(int i=0;i<N;i++) {
    if(arr1[i] == 'a') arr3[i] = a_start++;
    else arr3[i] = b_start++;
  }
  b_start = c_a1+2;
  a_start = 1;
  for(int i=0;i<N;i++) {
    if(arr2[i] == 'a') arr4[i] = a_start++;
    else arr4[i] = b_start++;
  }

  for(int i=0;i<N;i++) hash_[arr4[i]] = i+1;
  for(int i=0;i<N;i++) arr3[i] = hash_[arr3[i]];

  for(int i=N-1;i>=0;i--) {
    ans+= get_s(arr3[i]-1);
    update(arr3[i],1);
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input_swap_adj", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
      ans = 0;
      N =0;
      c_a1=c_a2=c_b1=c_b2=0;
      cin>>arr1;
      cin>>arr2;
      for(int i =0;i<100001;i++) {
        if(arr1[i]) {
          N++;
          if(arr1[i] == 'a') c_a1++;
          else c_b1++;
        }
        else break;
      }
      for(int i =0;i<100001;i++) {
        if(arr2[i]) {
          if(arr2[i] == 'a') c_a2++;
          else c_b2++;
        }
        else break;
      }
      if(c_a1 == c_a2 && c_b1==c_b2) {
        adj_swap();
        cout<<"#"<<test_case<<" "<<ans<<endl;
      } else cout<<"#"<<test_case<<" "<<"-1"<<endl;
	}
	return 0;
}
