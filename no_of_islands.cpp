#include<iostream>
#include<vector>

using namespace std;

bool visited[1000][1000] = {false};

int x_idx[4] = {-1, 0, 1,0};
int y_idx[4] = {0, 1,0,-1};

bool is_safe(int i,int j, int s, vector<vector<char>>& arr, int s1) {
  if(i>=0 && i<s && j>=0 && j<s1 && !visited[i][j] && arr[i][j] == '1') {
    return true;
   }
  return false;
}

void dfs(int i, int j, vector<vector<char>>& arr) {
  visited[i][j] = true;
  int s = arr.size();

  for(int k=0;k<4;k++) {
    int x = i + x_idx[k];
    int y = j + y_idx[k];
    int s1 = arr[0].size();
    if(is_safe(x,y,s,arr,s1)) {
      dfs(x,y,arr);
    }
  }
}

int numIslands(vector<vector<char>>& arr) {
  int s = arr.size();
  int ans = 0;
  if(!s) return ans;

  for(int i=0;i<s;i++) {
    for(int j=0;j<arr[i].size();j++) {
      if(!visited[i][j] && arr[i][j] == '1') {
        dfs(i,j, arr);
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  //vector<vector<char>> arr = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
  vector<vector<char>> arr = {{'1','0','1','1','0','1','1'}};
  cout<<numIslands(arr)<<endl;
  return 0;
}
