#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct node {
  int first;
  int second;
  node(int a = 0, int b = 0) {
    first = a;
    second = b;
  }
};

class Comp {
public:
  bool operator()(const node &p1, const node &p2) {
    return p1.second > p2.second;
  }
};

int N, K;
vector<int> arr;
vector<int> cost;
unordered_map<int, int> hash_;
priority_queue<node, vector<node>, Comp> pq;

long long cal() {
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (hash_.find(arr[i]) != hash_.end()) {
      hash_[arr[i]] += 1;
    } else
      hash_[arr[i]] = 1;
  }

  // min heap
  for (int i = 0; i < N; i++)
    pq.push(node(arr[i], cost[i]));

  for (int i = 1; i <= K; i++) {
    if (hash_.find(i) == hash_.end()) {
      node p = pq.top();
      pq.pop();
      int c = hash_[p.first];
      while (c == 1) {
        p = pq.top();
        pq.pop();
        c = hash_[p.first];
      }

      ans += p.second;
      hash_[p.first]--;
    }
  }

  return ans;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    arr.push_back(t);
  }
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    cost.push_back(t);
  }

  long long ans = cal();
  cout << ans << endl;
}
