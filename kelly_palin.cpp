#include<iostream>

using namespace std;

long long dp[11][11];
char arr[11];

void init() {
  for(int i=0;i<11;i++) arr[i] = '\0';
  for(int i=0;i<11;i++)
    for(int j=0;j<11;j++) dp[i][j] = 0;
}

size_t mystrlen(char const *str) {
    char const *pos=str;
    for (; *pos; ++pos);
    return pos-str;
}

long long cal(char *a) {
  int N = mystrlen(a);
  long long a1 = 0;
  for(int i=0;i<11;i++)
    for(int j=0;j<11;j++) dp[i][j] = 0;

  for(int i=0;i<11;i++) dp[i][i] = 1;
    for(int k=2;k<=N;k++) {
    for(int i=0;i<N-k+1 ;i++) {
      int j=i+k-1;
      if(k==2) {
        if(a[i] == a[i+1]) {
          dp[i][i+1] = 1;
        }
      } else {
        if(dp[i+1][j-1] && a[i] == a[j]) {
          dp[i][j] = 1;
        }
      }
    }
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      a1+= dp[i][j];
    }
   }

  return a1;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

long long ans;
void permute(char *a, int l, int r)
{
   int i;
   if (l == r) {
     long long t;
     t = cal(a);
     if(t > ans) ans = t;
     //cout<<ans<<endl;
     //return ans;
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
   //return ans;
}

int main() {
  int t;
  cin>>t;
  for(int i=1;i<=t;i++) {
    init();
    cin>>arr;
    int N = mystrlen(arr);
    //if(i==2) {
    ans = cal(arr);
    permute(arr,0,N-1);
    cout<<"#"<<i<<" "<<ans<<endl;
    //}
    }
}
