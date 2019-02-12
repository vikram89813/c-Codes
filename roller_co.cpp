#include <iostream>
#include <stdio.h>

using namespace std;


const int MAXN = 200000;

int CalcFinalSpeed(int N, int *a, int *b, int *p) {
	int v = 1;

	for (int i = 0; i < N; i++) {

		int CurRail = p[i];

		v = (int)(((long long)(a[CurRail])*v + b[CurRail]) % 1000000007);
	}
	return v;
}
int MinRailSpeed(int N, int *a, int *b);

int a[MAXN], b[MAXN];

int main(void) {
	setbuf(stdout, NULL);

	int TestCase; for (scanf("%d", &TestCase); TestCase--;) {
		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int answer = MinRailSpeed(N, a, b);
		static int tc = 0;
		printf("#%d %d\n", ++tc, answer);
	}
	return 0;
}
//=================================================================

#define MOD 1000000007

struct node {
  int d1;
  int d2;
  int idx;
};

node new_arr[200001];
node arr2[200001];
node arr3[200001];

bool comp(int a1,int b1, int a2, int b2) {
  long long t1 = (long long)b1 * (long long)(a2 -1);
  long long t2 = (long long)b2 * (long long)(a1-1);
  return t1 < t2;
}

void merge(node arr[],int l,int m,int r) {
  int l1 = m-l + 1;
  int l2 = r-m;

  for(int i=0;i<l1;i++) {arr2[i].d1 = arr[l+i].d1; arr2[i].d2 = arr[l+i].d2;arr2[i].idx = arr[l+i].idx;}
  for(int i=0;i<l2;i++) {arr3[i].d1 = arr[m+i+1].d1; arr3[i].d2 = arr[m+i+1].d2;arr3[i].idx = arr[m+i+1].idx;}
  int i= 0;
  int j=0;
  int k = l;
  while(i < l1 && j<l2) {
    if(comp(arr2[i].d1, arr2[i].d2, arr3[j].d1, arr3[j].d2)) {arr[k].d1 = arr2[i].d1; arr[k].d2 = arr2[i].d2;arr[k].idx = arr2[i].idx;i++;}
    else {arr[k].d1 = arr3[j].d1; arr[k].d2 = arr3[j].d2;arr[k].idx = arr3[j].idx;j++;}
    k++;
  }
  while(i<l1) {arr[k].d1 = arr2[i].d1;arr[k].d2 = arr2[i].d2;arr[k].idx = arr2[i].idx;i++;k++;}
  while(j<l2) {arr[k].d1 = arr3[j].d1;arr[k].d2 = arr3[j].d2;arr[k].idx = arr3[j].idx;j++;k++;}
}

void sort_(node arr[], int l,int r) {
  if(l<r) {
    int m = l+(r-l)/2;
    sort_(arr,l,m);
    sort_(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

int MinRailSpeed(int N, int *a, int *b) {
  for(int i =0;i<N;i++) {new_arr[i].d1 = a[i]; new_arr[i].d2 = b[i];new_arr[i].idx = i;}
  sort_(new_arr,0,N-1);

  long long v =1;
  for(int i=0;i<N;i++) {
    int idx = new_arr[i].idx;
    v = ((v * a[idx]) % MOD + b[idx]) % MOD;
  }
  return v % MOD;
}


