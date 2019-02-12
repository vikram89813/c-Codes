#include<iostream>
#include<unordered_map>

using namespace std;

#define M 3
#define N 3

int x[8] = {-1,-1,0,1,1,1,0,-1};
int y[8] = {0,1,1,1,0,-1,-1,-1};

unordered_map<string,bool> hash_;

bool is_safe(int x,int y) {
  return (x>=0 && y>=0 && x<M && y<N);
}

void dfs(int row,int col,bool visited[M][N],string str,char arr[M][N]) {
  visited[row][col] = true;
  str += arr[row][col];
  if(hash_[str]) cout<<str<<endl;

  for(int i=0;i<8;i++) {
    int x_id = row + x[i];
    int y_id = col + y[i];
    if(!visited[x_id][y_id] && is_safe(x_id,y_id))
      dfs(x_id,y_id,visited,str,arr);
  }
  str.erase(str.size()-1);
  visited[row][col] = false;
}

void findWords(char arr[M][N]) {
  bool visited[M][N];
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      visited[i][j] = false;

  string str = "";

  for(int i=0;i<M;i++)
    for(int j=0;j<M;j++)
      if(!visited[i][j])
        dfs(i,j,visited,str,arr);
}

int main()
{
    char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};
	string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
    for(auto i : dictionary) hash_[i] = true;
    cout << "Following words of dictionary are present\n";
    findWords(boggle);
    return 0;
}
