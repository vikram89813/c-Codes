#include<iostream>
#include<unordered_map>

using namespace std;

struct node {
  int node_no;
  int o_deg;
  node(int i, int d=0) {
    node_no = i;
    o_deg = d;
  }
};

int N,M;
unordered_map<int,int> parent;
vector<node> outdegree;

bool operator < (const node &a, const node &b) {
  return (a.o_deg < b.o_deg);
}

int main() {
  cin>>N>>M;
  for(int i=1;i<=N;i++) outdegree.push_back(node(i));

  sort(outdegree.begin(),outdegree.end());

  for(int i = 0;i<M;i++) {
    int a,b;
    cin>>a>>b;
    parent[b] = a;
  }
}
