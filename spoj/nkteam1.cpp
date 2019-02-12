#include <bits/stdc++.h>

using namespace std;

#define MAX 500009

int tree[MAX];

struct cand
{
    int first, second, third;
};

bool cmp(const cand &a, const cand &b)
{
    return (a.first==b.first)?((a.second==b.second)?(a.third<b.third):(a.second<b.second)):(a.first<b.first);
}

void update(int idx, int val, int n)
{
    while(idx<=n)
    {
        tree[idx]=min(tree[idx], val);
        idx+=idx&-idx;
    }
}

int read(int idx)
{
    int chk=INT_MAX;
    while(idx>0)
    {
        chk=min(tree[idx], chk);
        idx-=idx&-idx;
    }
    return chk;
}

int main()
{
    int t, n;
    //scanf("%d", &t);
    //while(t--)
    {
        scanf("%d", &n);
        cand dat[n+9];
        for(int i=0;i<n;i++)
        {
            scanf("%d", &dat[i].third);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d", &dat[i].second);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d", &dat[i].first);
        }
        for(int i=0;i<n;i++)
            printf("%d ", dat[i].first);
        sort(dat, dat+n, cmp);
        fill(tree, tree+n+9, INT_MAX);
        int exc=0;
        for(int i=0;i<n;i++)
        {
            int curr=read(dat[i].second);
            if(curr>dat[i].third)
                exc++;
            update(dat[i].second, dat[i].third, n+9);
        }
        printf("%d\n", exc);
    }
    return 0;
}
