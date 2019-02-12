#include<iostream>

using namespace std;

char stack[1005] = "";
int stack_pos[1005] = { 0 };
char in[1005] = "";

int N;
int pos;

void cal(int test_case) {
    for (int i = 0; i < N; ++i)
	{
    	if (pos != -1 && stack[pos] == '(' && in[i] == ')')
    	{
        	pos -= 1;
        	continue;
    	}

    	stack[++pos] = in[i];
    	stack_pos[pos] = i;
	}
    if (pos == -1)
	{
    	cout << "#" << test_case << " " << 0 << "\n";
        return;
	}
    int s = stack_pos[0];
	int e = stack_pos[pos];

	int e1 = stack_pos[pos / 2];
	int s2 = stack_pos[pos / 2 + 1];
    if (stack[0] == '(')
	{
    	cout << "#" << test_case << " 1\n" << s2 << " " << e << "\n";
	}
	else if (stack[pos] == ')')
	{
    	cout << "#" << test_case << " 1\n" << s << " " << e1 << "\n";
	}
    else
	{
    	int spos = 0;
    	for (spos = 0; spos <= pos; ++spos)
    	{
        	if (stack[spos] == '(')
        	{
            	break;
        	}
    	}
    	int j = stack_pos[spos];
    	if (j <= e1)
    	{
         	e1 = stack_pos[spos - 1];
    	}
    	else
    	{
          	s2 = j;
    	}
    	cout << "#" << test_case << " 2\n";
    	cout << s << " " << e1 << "\n" << s2 << " " << e << "\n";
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/* 
	The freopen function below opens input.txt in read only mode and 
	sets your standard input to work with the opened file. 
	When you test your code with the sample data, you can use the function
	below to read in from the sample data file instead of the standard input.
	So. you can uncomment the following line for your local test. But you
	have to comment the following line when you submit for your scores.
	*/

	freopen("input_parenthesis", "r", stdin);
	cin>>T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cin >> in;
		pos = -1;
		if (N % 2)
		{
    		cout << "#" << test_case << " -1\n";
    		continue;
		}
        cal(test_case);
	}
	return 0;//Your program should return 0 on normal termination.
}
