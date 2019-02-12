typedef struct {
	int strike;
	int ball;
} Result;

#define N 4
Result query(int guess[]);

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

bool check(int *test, int idx, Result result)
{
  Result new_res;
  new_res.strike = 0;
  new_res.ball = 0;
  for (int i = 0; i< N; ++i)
  {
    if (test[i] == num_arr[idx][i])
    new_res.strike++;
    else if (num_hash[idx][test[i]] > 0)
    new_res.ball++;
  }
  if (new_res.strike == result.strike &&
  new_res.ball == result.ball) return true;
  else return false;
}

void doUserImplementation(int guess[]) {
  fill_num();

  Result result;
  int *test;

  for (int i= 0; i < count; i++)
  {
    if (!visited[i]) continue;
    test = num_arr[i];
    result = query(test);
    if (result.strike == 4) break;
    visited[i] = false;
    for(int j = i + 1; j < count; j++)
    {
      if (!check(test, j, result)) visited[j] = false;
    }
  }
  for (int i = 0; i < 4; i++) guess[i] = test[i];
}

