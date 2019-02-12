#include <cstdio>

int n,k,ans=0,s[150005];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
      scanf("%d",&s[i]),s[i]+=s[i-1];

    for(int j=0;j<=n-k;j++)
      if(s[ans+k]-s[ans]>s[j+k]-s[j])
        ans=j;

    printf("%d\n",ans+1);
}
