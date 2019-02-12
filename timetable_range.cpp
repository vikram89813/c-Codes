#include<iostream>

using namespace std;

int bit_s[1000001];
int bit_e[1000001];

int get_s(int idx,bool flag) {
  int s=0;
  while(idx>0) {
    if(flag) {
      s+=bit_s[idx];
      idx-= idx & (-idx);
    }
    else {
      s+=bit_e[idx];
      idx-= idx & (-idx);
    }
  }
  return s;
}

void update(int idx,int val, bool flag) {
  while(idx<=1000001) {
    if(flag) {
      bit_s[idx]+=val;
      idx+= idx & (-idx);
    }
    else {
      bit_e[idx]+=val;
      idx+= idx & (-idx);
    }
  }
}

int cal(int l,int h) {
  int ans=0;
  update(l,1,true);
  update(h-1,1,false);
  int s1 = get_s(l,true);
  int e1 = get_s(l-1, false);
  ans += (s1-e1);

  int s2 = get_s(h-1,true);
  ans += (s2-s1);
  return ans;
}

int main() {
  int n;
  cin>>n;
  fill(bit_s,bit_s+1000001,0);
  fill(bit_e,bit_e+1000001,0);
  while(n--) {
    int a,b;
    cin>>a>>b;
    cout<<cal(a,b)<<endl;
  }
  return 0;
}
