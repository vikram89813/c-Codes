struct node {
    int x, y, cnt;
    struct node* next;
};
typedef struct node node;

struct stamp
{
    int cnt, s;
    char a[100][100];
    node* list;
};
typedef struct stamp stamp;

struct trie {
    int id, eos;
    struct trie *a[10];
};
typedef struct trie trie;


// Data
int N;
stamp stamps[100 + 5];
node lists[20000 + 5];
trie tries[100 * 5 + 5];
int llen, gid, tlen;

trie t;

//
void addid(trie *tr, int id) {
    while (id) {
        if (!tr->a[id%10]) {
            trie *tmp = &tries[tlen++];
            for(int i=0;i<10;i++)
                tmp->a[i]=0;
            tmp->eos = tmp->id = 0;
            tr->a[id%10] = tmp;
        }
        tr = tr->a[id%10];
        id = id/10;
    }
    tr->eos = 1;
    tr->id = gid;
}

int getid(trie *tr, int id)
{
    while (tr && id) {
        if (tr->a[id%10]) {
            tr = tr->a[id%10];
            id = id/10;
        } else
            break;
    }
    if (!tr)
        return 0;
    return (tr->eos == 1 ? tr->id : 0);
}

//
void init(int n)
{
    N = n;
    for (int i=1;i<=gid;i++)
        stamps[i].list=0;
    llen = gid = tlen = 0;
    t = tries[tlen++];
    for(int i=0;i<10;i++)
        t.a[i]=0;
    t.eos = t.id = 0;
}

void addStamp(int id, int M, char pattern[100][100])
{
    ++gid;
    addid(&t, id);
    stamp *tmp = &stamps[gid];
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            tmp->a[i][j]=pattern[i][j];
    tmp->cnt = 0;
    tmp->s = M;
}

void press(int id, int x, int y) {
    int lid = getid(&t, id);
    node *nd = &lists[llen++];
    nd->x = y;
    nd->y = x;
    nd->cnt = stamps[lid].cnt;
    nd->next = stamps[lid].list;
    stamps[lid].list = nd;
    stamps[lid].cnt  = (stamps[lid].cnt + 1) % 4;
}

void erase(int id) {
    int lid = getid(&t, id);
    if(lid)
        stamps[lid].list = 0;
}

int getAverage(int x, int y) {
    int sum = 0;
    int l, m, a, b, s, cnt;
    for (int k = 1; k <= gid; k++) {
        node *lst = stamps[k].list;
        s = stamps[k].s;
        while(lst) {
            l = lst->x;
            m = lst->y;
            cnt = lst->cnt;
            for (int  i = 0; i < 7; i++) {
                a = y + i;
                if (a <l || a >= l + s || a >= N)
                    continue;
                for (int j = 0; j< 7; j++) {
                    b = x + j;
                    if (b < m || b >= m + s || b >= N)
                        continue;
                    switch(cnt) {
                        case 0:
                            sum += stamps[k].a[a-l][b-m];
                            break;
                        case 1:
                            sum += stamps[k].a[b-m][s-1-(a-l)];
                            break;
                        case 2:
                            sum += stamps[k].a[s-1-(a-l)][s-1-(b-m)];
                            break;
                        case 3:
                            sum += stamps[k].a[s-1-(b-m)][a-l];
                            break;
                    }
                }
            }
            lst = lst->next;
        }
    }
    return sum/49;
}
