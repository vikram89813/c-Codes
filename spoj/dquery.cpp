#include<bits/stdc++.h>

using namespace std;

struct query_s {
  int l,r,id;
};

int N;
int arr[30005];
int bit[30005];
int Q;
int visit[1000005];
query_s query_arr[200005];
int ans[200005];

bool operator < (const query_s &a, const query_s &b) {
  return a.r < b.r ? true : (a.r==b.r ? a.l<b.l : false);
}


int get_s(int idx) {
  int s =0;
  while(idx>0) {
    s+=bit[idx];
    idx-= idx & (-idx);
  }
  return s;
}

void update(int idx,int val) {
  while(idx<=N) {
    bit[idx]+=val;
    idx+= idx & (-idx);
  }
}

void cal() {
  int max_ = *max_element(arr,arr+N);
  fill(bit,bit+N+1,0);
  fill(visit,visit+max_+1,-1);

  int c = 0;
  for(int i=0;i<N;i++) {
    if(visit[arr[i]] != -1) update(visit[arr[i]] + 1, -1);
    visit[arr[i]] = i;
    update(i+1,1);
    while(c < Q && query_arr[c].r == i) {
      ans[query_arr[c].id] = get_s(query_arr[c].r + 1) - get_s(query_arr[c].l);
      c++;
    }
  }
}

int main() {
  cin>>N;
  for(int i=0;i<N;i++) scanf("%d", &arr[i]);
  cin>>Q;
  int c = 0;
  for(int i=0;i<Q;i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    query_arr[c].l = a-1;
    query_arr[c].r = b-1;
    query_arr[c].id = c;
    ++c;
  }
  sort(query_arr,query_arr+Q);
  cal();
  for(int i =0;i<Q;i++) printf("%d\n",ans[i]);
}





