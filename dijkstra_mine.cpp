#include<iostream>
#include<queue>
#include<list>
#include<climits>

using namespace std;

typedef pair<int, int> pi;

class Graph{
  int V;
  list<pi> *adj;
  priority_queue<pi,vector<pi>,greater<pi>> q;
  int *dist;
  bool *visited;
  public:
    Graph(int v) {
      V=v;
      adj = new list<pi>[v];
      dist = new int[v];
      visited = new bool[v];
      for(int i=0;i<v;i++) dist[i] = INT_MAX;
      for(int i=0;i<v;i++) visited[i] = false;
    }
    void addEdge(int src,int des,int w) {
      adj[src].push_back(make_pair(des,w));
      adj[des].push_back(make_pair(src,w));
    }
    void dijkstra(int src);
};

void Graph::dijkstra(int src) {
  dist[src] = 0;
  for(int i=0;i<V;i++) q.push(make_pair(dist[i],i));
  while(!q.empty()) {
    pi p = q.top();
    q.pop();
    int u = p.second;
    if(visited[u]) continue;
    visited[u] = true;
    for(auto i:adj[u]) {
      int dest = i.first;
      int w = i.second;
      if(!visited[dest] && dist[u] != INT_MAX && dist[u] + w < dist[dest])
        dist[dest] = dist[u] + w;
        q.push(make_pair(dist[dest],dest));
    }
  }

  for(int i=0;i<V;i++) {
    cout<<i<<" "<<dist[i]<<endl;
  }
}

int main()
{
    int v = 9;
    Graph g(v);
    g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);
    g.dijkstra(0);
    return 0;
}
