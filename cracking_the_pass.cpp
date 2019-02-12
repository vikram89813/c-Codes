#include<iostream>

using namespace std;

int M,N;
long long dp[101][101];

void cal() {
  for(int i=1;i<101;i++) dp[1][i] = 1;
  for(int i=2;i<101;i++) {
    for(int j=i;j<101;j++) {
      dp[i][j] = ((dp[i-1][j-1] + dp[i][j-1]) * i) % 1000000007;
    }
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input_password", "r", stdin);
	cin>>T;
    cal();
	for(test_case = 1; test_case <= T; ++test_case)
	{
      cin>>M>>N;
      cout<<"#"<<test_case<<" "<<dp[M][N]<<endl;
	}
	return 0;
}
