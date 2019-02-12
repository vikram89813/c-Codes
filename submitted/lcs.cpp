#include<iostream>

using namespace std;

string X;
string Y;
int m,n;
int L[1005][1005];

int max_(int a,int b) {
  return a>=b?a:b;
}

void clear() {
  for(int i =0;i<1005;i++)
    for(int j=0;j<1005;j++)
      L[i][j] = 0;
}

int lcs()
{
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max_(L[i-1][j], L[i][j-1]);
     }
   }

   return L[m][n];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input_lcs", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
      clear();
      cin>>X;
      cin>>Y;
      m = X.size();
      n = Y.size();
      int ans = lcs();
      cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;
}
