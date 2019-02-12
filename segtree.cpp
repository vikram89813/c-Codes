#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> arr;
int st[32];
int N;

int getSum(int l,int r,int ql,int qh,int pos) {
  if(ql <= l && qh >= r) {
    return st[pos];
  }
  if(r < ql || l > qh) return INT_MAX;
  int m = l + (r-l)/2;
  return min(getSum(l,m,ql,qh,2*pos + 1), getSum(m+1,r,ql,qh,2*pos+2));
}

int constructST(int l,int r,int pos) {
  if(l==r) {
    st[pos] = arr[l];
    return st[pos];
  }
  int m = l + (r-l)/2;
  st[pos] = min(constructST(l,m,2*pos+1), constructST(m+1,r,2*pos+2));
}

/*void updateValueH(int l,int r,int idx,int p_val, int val,int pos) {
  if(idx < l || idx > r) return;
  st[pos] = INT_MAX;
  st[pos] = min(st[pos],val);
  if(l!=r) {
    int m =l + (r-l)/2;
    updateValueH(l,m,idx,p_val,val,2*pos+1);
    updateValueH(m+1,r,idx,p_val,val,2*pos+2);
  }
}*/

void updateValue(int idx, int val) {
  int prev_val = arr[idx];
  arr[idx] = val;
  constructST(idx,N-1,0);
}

int main()
{
    arr= {1, 3, 2, 7, 9, 11};
    N=6;
    for(int i=0;i<32;i++) st[i] = INT_MAX;
    constructST(0,N-1,0);
    int qs = 1;
    int qe = 7;
    printf("Minimum of values in range [%d, %d] is = %d\n",
                        qs, qe, getSum(0, N-1, qs, qe,0));
    updateValue(2,15);
    printf("Minimum of values in range [%d, %d] is = %d\n",
                        qs, qe, getSum(0, N-1, qs, qe,0));
    return 0;
}

