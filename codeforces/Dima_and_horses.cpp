#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int N,M;
vector<int> graph[300001];
int col[300001];

void dfs(int v)
{
  for(auto u : graph[v])
  {
    if(!col[u])
    {
      col[u] = 3-col[v];
      dfs(u);
    }
  }

  int count = 0;
  for(auto u : graph[v])
  {
    if(col[u] == col[v])
      count++;
  }
  
  if(count>1)
    col[v] = 3-col[v];
}

int main()
{
  ios_base::sync_with_stdio(false);
  int v,u;
  cin>>N>>M;
  for (int i=0;i<M;i++)
  { 
   // scanf("%d%d",&v,&u);
    cin>>v>>u;
    v--;u--;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  for (int i=0;i<N;i++)
  { 
    if (!col[i])
    { 
      col[i]=1;
      dfs(i);
    }
  }

  for (int i=0;i<N;i++) 
    cout<<col[i]-1;

  cout<<endl;

  return 0;
}
