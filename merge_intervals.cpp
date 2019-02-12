#include<bits/stdc++.h>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& arr) {
  vector<Interval> res;
  sort(arr.begin(),arr.end(), [] (Interval &a, Interval &b) {
    return a.start < b.start;
  });
  int i=1;
  int s = arr.size();
  Interval a= arr[0];
  while(i<s-1) {
    Interval b = arr[i];
    if(a.end >= b.start) {
      res.push_back(Interval(a.start, max(a.end,b.end)));
      a = Interval(a.start, max(a.end,b.end));
    } else {
      res.push_back(b);
      a = b;
    }
    i++;
  }

  while(i<s) {
    res.push_back(arr[i]);
    i++;
  }
  return res;
}

int main() {
  vector<Interval> arr = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
  vector<Interval> t = merge(arr);
  for(auto i : t) cout<<i.start<<" "<<i.end<<endl;
  return 0;
}
