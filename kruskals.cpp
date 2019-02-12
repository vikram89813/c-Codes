#include<iostream>
#include<list>
#include<vector>

using namespace std;

struct edge {
  int src;
  int dest;
  int w;
};

struct subset{
  int parent;
  int rank;
};

bool operator < (const edge &a, const edge &b) {
  return (a.w < b.w);
}

class Graph{
  int V;
  list<edge> arr;
  list<edge> res;
  vector<subset> sub;
  public:
    Graph(int v) {
      V=v;
    }
    void addEdge(int src,int dest,int weight) {
      edge e;
      e.src = src;
      e.dest = dest;
      e.w = weight;
      arr.push_back(e);
    }
    void sort_() {
      arr.sort();
    }
    void print_() {
      for(auto i : res) cout<<i.src<<" "<<i.dest<<" "<<i.w<<endl;
    }
    int find_(int i) {
      if(sub[i].parent != i)
        sub[i].parent = find_(sub[i].parent);
      return sub[i].parent;
    }
    void union_(int x,int y) {
      int x_ = find_(x);
      int y_ = find_(y);

      if(sub[x_].rank < sub[y_].rank)
        sub[x_].parent = y_;
      else if(sub[x_].rank > sub[y_].rank)
        sub[y_].parent = x_;
      else {
         sub[y_].parent = x_;
         sub[x_].rank++;
      }
    }
    void mst();
};

void Graph::mst() {
  sort_();
  for(int i=0;i<V;i++) {
    subset s;
    s.parent = i;
    s.rank = 0;
    sub.push_back(s);
  }
  int e=0;
  while(e<V-1) {
    edge eg = arr.front();
    arr.pop_front();
    int src = eg.src;
    int dest = eg.dest;
    int x = find_(src);
    int y = find_(dest);
    if(x!=y) {
      res.push_back(eg);
      e++;
      union_(x,y);
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0,1,10);
  g.addEdge(1,3,15);
  g.addEdge(3,2,4);
  g.addEdge(2,0,6);
  g.addEdge(0,3,5);
  g.mst();
  g.print_();
  return 0;
}
