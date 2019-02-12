#include<bits/stdc++.h>

using namespace std;

#define MAX 500005

struct node {
  int first,second,third;
};

int N;
node ranks[MAX];
int bit[MAX];

bool cmp(node &a,node &b) {
  return a.first<=b.first;
}

int read_(int idx) {
  int c=INT_MAX;
  while(idx>0) {
    c=min(c,bit[idx]);
    idx-= idx & (-idx);
  }
  return c;
}

void update(int idx,int v) {
  while(idx<=N) {
    bit[idx] = min(bit[idx],v);
    idx+= idx & (-idx);
  }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);

        for (int idx = 0; idx < N; idx++) {
            scanf("%d%d%d", &ranks[idx].first, &ranks[idx].second, &ranks[idx].third);
        }

        sort(ranks, ranks + N, cmp);

        fill(bit, bit + N + 5, INT_MAX);

        int excellent = 0;
        for (int idx = 0; idx < N; idx++) {
            int curr = read_(ranks[idx].second);

            if (curr > ranks[idx].third) {
                excellent++;
            }

            update(ranks[idx].second, ranks[idx].third);
        }

        printf("%d\n", excellent);
    }
    return 0;
}

