#include<iostream>

using namespace std;

struct node {
  char c;
  int idx;
};

char in[1001];
node stack[1001];

int N;
int top;

void cal(int test_case) {
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input_parenthesis", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cin >> in;
		top = -1;
		if (N % 2)
		{
    		cout << "#" << test_case << " -1\n";
    		continue;
		}
        cal(test_case);
	}
	return 0;
}
