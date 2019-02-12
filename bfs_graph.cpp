#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
  int V;
  list<int> *adj;

  public:
    Graph(int v) {
      V=v;
      adj = new list<int>[v];
    }
    void addEdge(int a,int b) {
      adj[a].push_back(b);
    }
    void BFS(int v);
    void DFS(int v);
    void DFS_util(int v, vector<bool> &visited);
};

void Graph::BFS(int v) {
  bool visited[V];
  queue<int> q;
  q.push(v);
  while(!q.empty()) {
    int a = q.front();
    q.pop();
    visited[a] = true;
    cout<<a<<" ";
    for(auto i : adj[a])
      if(!visited[i]) q.push(i);
  }
}

void Graph::DFS_util(int v,vector<bool> &visited) {
  visited[v] = true;
  cout<<v<<" ";
  for(auto i : adj[v])
    if(!visited[i])
      DFS_util(i,visited);
}

void Graph::DFS(int v) {
  vector<bool> visited(V,false);
  DFS_util(v,visited);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout<<endl<<"DFS: "<<endl;
    g.DFS(2);
    cout<<endl;
    return 0;
}
