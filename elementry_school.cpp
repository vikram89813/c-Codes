#include<iostream>

using namespace std;

int N;
int arr[101];
int ans;

void cal(int sum) {
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input_elementry", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
      cin>>N;
      for(int i=0;i<N;i++) cin>>arr[i];
      cal(arr[0]);
      cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;
}
