#include<iostream>
#include<list>
#include<stack>
#include<vector>

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
    void toposort();
    void dfsutil(int v,vector<bool> &visited, stack<int> &s);
};

void Graph::dfsutil(int v,vector<bool> &visited, stack<int> &s) {
  visited[v] = true;
  for(auto i: adj[v])
    if(!visited[i])
      dfsutil(i,visited,s);

  s.push(v);
}

void Graph::toposort() {
  stack<int> s;
  vector<bool> visited(V,false);
  for(int i=0;i<V;i++)
    if(!visited[i])
      dfsutil(i,visited,s);

  while(!s.empty()) {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.toposort();

    return 0;
}
