#include <cstdio>
int n,k,s,w[2048][2048]={{0,1}},M=1000000007;
int main() {
  scanf("%d%d",&n,&k);
  for(int i=0;i<k;++i)
    for(int j=1;j<=n;++j)
      for(int m=j;m<=n;m+=j)
        (w[i+1][m]+=w[i][j])%=M;
  for(int i=1;i<=n;++i)(s+=w[k][i])%=M;
  printf("%d\n",s);
}
