#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N              4
#define MAX_QUERYCOUNT 1000000

static int digits[N];
static int digits_c[10];

static int T;

extern void doUserImplementation(int guess[]);

static int querycount; 

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;

typedef struct {
	int strike;
	int ball;
} Result;

static bool isValid(int guess[]) {
	int guess_c[10];
	
	for (int count = 0; count < 10; ++count) guess_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0) return false;
		guess_c[guess[idx]]++;
	}
	return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[]) {
	Result result;
	
	if (querycount >= MAX_QUERYCOUNT) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
    querycount++;
		
	if (!isValid(guess)) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
	result.strike = 0;
	result.ball = 0;

	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == digits[idx])
			result.strike++;
		else if (digits_c[guess[idx]] > 0)
			result.ball++;

	return result;
}

static void initialize() {
	for (int count = 0; count < 10; ++count) digits_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		char c;
		do scanf("%c", &c); while(c < '0' || c > '9');
		digits[idx] = c - '0';
		digits_c[digits[idx]]++;
	}
	
	querycount = 0;
}

static bool check(int guess[]) {
	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] != digits[idx]) return false;
	return true;
}

int num_arr[5041][4];
bool visited[5041];
int num_hash[5041][10];
int count;

void fill_num() {
  count = 0;

  for(int i=0;i<5041;i++)
    for(int j =0;j<10;j++) num_hash[i][j] = 0;

  for(int i =0;i<5041;i++) visited[i] = true;

  for(int i =0;i<10;i++)
    for(int j=0;j<10;j++)
      for(int k=0;k<10;k++)
        for(int l=0;l<10;l++) {
          if(i != j && i != k && i!= l && j!= k && j!= l && k!= l) {
            num_arr[count][0] = i;
            num_arr[count][1] = j;
            num_arr[count][2] = k;
            num_arr[count][3] = l;
            num_hash[count][i]++;
            num_hash[count][j]++;
            num_hash[count][k]++;
            num_hash[count][l]++;
            count++;
          }
        }
}

bool compare(int *myTry, int k, Result result)
{
  Result new_result;
  new_result.strike = 0;
  new_result.ball = 0;
  for (int idx = 0; idx < N; ++idx)
  {
    if (myTry[idx] == num_arr[k][idx])
    new_result.strike++;
    else if (num_hash[k][myTry[idx]] > 0)
    new_result.ball++;
  }
  if (new_result.strike == result.strike &&
  new_result.ball == result.ball) return true;
  else return false;
}

void doUserImplementation(int guess[]) {
  fill_num();

  Result result;
  int *myTry;
  for (int i= 0; i < count; i++)
  {
    if (visited[i] == false) continue;
    myTry = num_arr[i];
    result = query(myTry);
    if (result.strike == 4) break;
    visited[i] = false;
    for(int k = i + 1; k < count; k++)
    {
      if (compare(myTry, k, result) == false)
        visited[k] = false;
    }
  }
  for (int i = 0; i < 4; i++) guess[i] = myTry[i];
}

int main() {
	int total_score = 0;
	int total_querycount = 0;;

    freopen("input_baseball", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase) {
        initialize();

        int guess[N];
		doUserImplementation(guess);

		if (!check(guess)) querycount = MAX_QUERYCOUNT;
        if (querycount <= limit_query) total_score++;
		printf("#%d %d\n", testcase, querycount);
		total_querycount += querycount;
    }
	if (total_querycount > MAX_QUERYCOUNT) total_querycount = MAX_QUERYCOUNT;
	printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
	return 0;
}
