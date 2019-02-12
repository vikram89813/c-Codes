#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pb          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())
#define MAX 100
#define INF 1000000007
#define MOD 1000000007

#define N 50555
#define BLOCK 224

struct node
{
    int l, r, i;
};

int cnt[2], dat[N], ans[N], answer=0;

void add(int pos)
{
    if(dat[pos]==1)
        cnt[0]++;
    if(dat[pos]==-1)
        cnt[1]++;
}

void remove(int pos)
{
    if(dat[pos]==1)
        cnt[0]--;
    if(dat[pos]==-1)
        cnt[1]--;
}

bool cmp(node a, node b)
{
    if(a.l/BLOCK!=b.l/BLOCK)
        return a.l<b.l;
    return a.r<b.r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    node q[N];
    cin>>n>>m;
    fo(i, n)
        cin>>dat[i];
    fo(i, m)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--;q[i].r--;
        q[i].i=i;
    }
    sort(q, q+m, cmp);
    int currL=0, currR=0;
    fo(i, m)
    {
        int L=q[i].l, R=q[i].r;
        while(currL<L)
        {
            remove(currL);
            currL++;
        }
        while(currL>L)
        {
            add(currL-1);
            currL--;
        }
        while(currR<=R)
        {
            add(currR);
            currR++;
        }
        while(currR>R+1)
        {
            remove(currR);
            currR--;
        }
        ans[q[i].i]=min(cnt[0], cnt[1])*2;
    }
    fo(i, m)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
