#include <iostream>

using namespace std;

char str[1001];
int table[1001][1001];
int n;

void init() {
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) table[i][j] = 0;
}

int cal()
{
	int maxLength = 1;
	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	for (int i = 0; i < n-1; ++i)
	{
		if (str[i] == str[i+1])
		{
			table[i][i+1] = true;
			maxLength = 2;
		}
	}
	for (int k = 3; k <= n; ++k)
	{
		for (int i = 0; i < n-k+1 ; ++i)
		{
			int j = i + k - 1;

			if (table[i+1][j-1] && str[i] == str[j])
			{
				table[i][j] = true;

				if (k > maxLength)
				{
					maxLength = k;
				}
			}
		}
	}
	return maxLength;
}

int main() {
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    cin>>str;
    n=0;
    int i=0;
    init();
    while(str[i]) {n++;i++;}
    int ans = cal();
    cout<<"#"<<t<<" "<<ans<<endl;
  }
  return 0;
}

