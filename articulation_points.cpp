#include<iostream>
#include<list>
#include<vector>
#include<set>

using namespace std;

class Graph{
  int V;
  list<int> *adj;
  set<int> ap;
  public:
  Graph(int v) {
    V=v;
    adj = new list<int>[v];
  }
  void addEdge(int a,int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  void AP();
  void print_();
  void ap_util(int u, vector<bool> &visited, vector<int> &low, vector<int> &disc, vector<int> &parent);
};

void Graph::ap_util(int u,vector<bool> &visited, vector<int> &low, vector<int> &disc, vector<int> &parent) {
  visited[u] = true;
  static int time = 0;
  low[u] = disc[u] = time++;
  int child = 0;
  for(auto v : adj[u]) {
    if(!visited[v]) {
      parent[v] = u;
      child++;
      ap_util(v,visited,low,disc,parent);
      low[u] = min(low[u],low[v]);
      if(parent[u] == -1 && child > 1) ap.insert(u);
      if(parent[u] != -1 && low[v] >= disc[u])
        ap.insert(u);
    } else {
      if(parent[u] != v )
        low[u] = min(low[u],disc[v]);
    }
  }
}

void Graph::AP() {
  vector<bool> visited(V,false);
  vector<int> low(V,0);
  vector<int> disc(V,0);
  vector<int> parent(V,-1);
  for(int i=0;i<V;i++) {
    if(!visited[i])
      ap_util(i,visited,low,disc,parent);
  }
  print_();
}

void Graph::print_() {
  for(auto i : ap) cout<<i<<" ";
  cout<<endl;
}

int main()
{
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
    return 0;
}
