#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache {
  list<int> l;
  int size_;
  unordered_map<int, list<int>::iterator> m;
  public:
    LRUCache(int s) : size_(s) {}
    void refer(int v);
    void display();
};

void LRUCache::display() {
    for(auto i: l) cout<<i<<" ";
    cout<<endl;
}

void LRUCache::refer(int v) {
  if(m.find(v) == m.end()) {
    if(l.size() == size_) {
      int t = l.back();
      l.pop_back();
      m.erase(t);
    }
  } else l.erase(m[v]);

  l.push_front(v);
  m[v] = l.begin();
}

int main() {
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
