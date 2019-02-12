#include <iostream>
using namespace std;
#define MAX_SIZE 1028
#define MAX_CALLS 25000
char map_mat[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE / 2], queries[MAX_SIZE], index[MAX_SIZE], orig_result[MAX_SIZE / 2];
int calls, n;
int seed = 3;                                                          // seed may change for testing
extern void Init(int n, char map_mat[MAX_SIZE][MAX_SIZE]);
extern void findresult(int x, int y, int result[MAX_SIZE / 2]);
static int pseudo_rand(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}
int compare(int a, int b)
{
	if (calls >= MAX_CALLS)
		return -1;
	calls++;
	if (a<1 || b<1 || a>n || b>n)
		return -1;
	if (index[a]<index[b])
		return 1;
	if (index[b]<index[a])
		return 0;
	return -1;
}
int main()
{
	int t, T;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	calls = 0;
	for (t = 1; t <= T; t++)
	{
		cin >> n;
		int i, j, x, y;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				int x = pseudo_rand() % 1001;
				if (x % 5)
					map_mat[i][j] = '.';
				else
					map_mat[i][j] = '*';
			}
		}
		cin >> x >> y;
		for (i = 0; i < n; i++) {
			cin >> queries[i];
			index[queries[i]] = i;
		}

		Init(n, map_mat);
		findresult(x, y, result);
		int answer = 0, queries = n / 2;
		for (i = 0; i < queries; i++)
			cin >> orig_result[i];
		for (i = 0; i<queries; i++)
			if (result[i] == orig_result[i])
				answer++;
		cout << "#" << t << " " << answer / queries << '\n';
	}
	cout << "Total Number of Compare Calls: " << calls << '\n';
	
	return 0;
}