#include <iostream>
#include <algorithm>
using namespace std;

long long INF=2e18;
long long b, ans, dp[2 << 21]; pair<int, pair<int, int>> p[101];

int main() {
  int n, m, x, y;
  cin>>n>>m>>b;

	for (int i = 0; i < n; ++i) {
      cin>>p[i].second.first>>p[i].first>>x;

		for (int j = 0; j < x; ++j) {
        cin>>y;

	    p[i].second.second |= 1 << (y - 1);
	  }
	}

	sort(p, p + n);

	for (int i = 1; i < (1<<m)+1; ++i)
    dp[i] = INF;

  ans = INF;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1<<m); j++) {
			if ((j^p[i].second.second) & p[i].second.second) {
                int k;
				k = j | p[i].second.second;
				dp[k] = min(dp[k], dp[j] + p[i].second.first);
			}
		}

		if (dp[(1<<m)-1] < INF)
          ans = min(ans, dp[(1<<m)-1] + p[i].first * b);
	}

	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}
