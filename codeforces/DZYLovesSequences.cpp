#include<bits/stdc++.h>
using namespace std;

int a[100005],i,n,l[100005],r[100005],ans=-1;

main()
{
    scanf("%d",&n);
    a[n+1]=2e9;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        l[i]=(a[i]>a[i-1]?l[i-1]+1:1);
        ans=max(ans,l[i]);
    }

    if (ans<n)
      ans++;

    for (i=n;i>=1;i--)
    {
        r[i]=(a[i]<a[i+1]?r[i+1]+1:1);

        if (a[i-1]+1<a[i+1]) {
          ans=max(ans,r[i+1]+l[i-1]+1);
        }
    }
    printf("%d\n",ans);
}
