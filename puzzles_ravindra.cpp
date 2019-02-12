/**
 * Author: Raveendra Karu
 * Date  : 2016-06-23
 * SWC professional test: Solve dynamic puzzle
 */
#pragma GCC optimize ("-Ofast")
#define DEBUG 0
int N, M, K;

struct list {
    int id;
    struct list* next;
};
typedef struct list list;

struct trie {
    struct trie* a[3];
    list* lst[4];
};

struct piece {
    int list[4][6]; // 0-top, 1-right, 2-down, 3-left
    int count[4];
    int sig[4];
    int values[4][15+1];
};
typedef struct piece piece;

piece pieces[49*49 + 10];
trie tries[50*50*16];
//trie tries[50*50*16*4];
list lists[50*50*6];
int tlen;
int llen;
int gid;
int topleft[6];
int tcount;
int V[49*49 + 10];
int P[49*49 + 10];
trie t;

trie* gettrie()
{
    trie* tmp = &tries[tlen++];
    tmp->a[0]=tmp->a[1]=tmp->a[2]=0;
    tmp->lst[0]=tmp->lst[1]=tmp->lst[2]=tmp->lst[3]=0;
    return tmp;
}
 
void addlist(trie* tr, int* arr, int k, int id)
{
    int i = 0;
    while(i < M) {
        if (!tr->a[arr[i]+1]) {
            tr->a[arr[i]+1] = gettrie();
        }
        tr = tr->a[arr[i]+1];
        i++;
    }
    list* tmp = &lists[llen++];
    tmp->id = id;
    tmp->next = tr->lst[k];
    tr->lst[k] = tmp;
}

list* getlist(trie* tr, int* arr, int k)
{
    int i = 0, j = 0;
    while(tr && i < M) {
        if (arr[i]) {
            j = (arr[i]+1)^2;
        } else
            j = arr[i]+1;

        if (tr->a[j]) {
            tr = tr->a[j];
        }
        i++;
    }
    if (!tr)
        return 0;

    return tr->lst[k];
}

void print()
{
#if DEBUG
    for (int i=1; i<= N; i++) {
        for (int j = 1; j <= N; j++)
        {
            cout << P[(i-1)*N + j] << " ";
        }
        cout << endl;
    }
    for (int i=1; i <= gid; i++) {
        cout << endl << i << ": "<< endl;
        for (int l = 0; l < 4; l++) {
            cout << l << ": ";
            for (int j = 0; j< pieces[i].count[l];j++)
                cout << pieces[i].list[l][j] << " ";
            cout << endl;
        }
    }
#endif
}

void init(int n, int m, int k)
{
    for (int id=1; id <= gid; id++) {
        V[id] = P[id] = 0;
        pieces[id].count[0]=pieces[id].count[1]=pieces[id].count[2]=pieces[id].count[3]=0;
        pieces[id].sig[0]=pieces[id].sig[1]=pieces[id].sig[2]=pieces[id].sig[3]=0;
    }
    N = n;
    M = m;
    K = k;
    gid = 0;
    tcount = 0;
    tlen = 0;
    llen = 0;
    t = *(gettrie());
}

void addPiece(int pie[])
{
    ++gid;
    int l = 0;
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(pie[l])
                pieces[gid].sig[i] += 1;
            pieces[gid].values[i][j] = pie[l++];
        }
        addlist(&t, pieces[gid].values[i], i, gid);
    }

    l=4*M-1;
    for (int i=3;i>=2;i--)
    {
        for(int j=0; j<M;j++)
        {
            if(pie[l])
                pieces[gid].sig[i] += 1;
            pieces[gid].values[i][j] = pie[l--];
        }
        addlist(&t, pieces[gid].values[i], i, gid);
    }
}

void preprocess()
{
    for(int i=1; i <= gid; i++) {
        for (int j=0; j<4; j++) {
            list* lst = getlist(&t, pieces[i].values[j], j^2);
            int cnt = 0;
            while (lst) {
                pieces[i].list[j][cnt++] = lst->id;
                lst = lst->next;
            }
            pieces[i].count[j] = cnt;
        }
    }
}

int findans(int p, int id)
{
        if (p > N) { //top //CHK
            int tidx = P[(p/N-1)*N + (p%N)];
            int tcnt =  pieces[id].count[0];
            if (!tcnt)
                return 0;
            int i = 0;
            for (i=0;i<tcnt;i++){
                if (pieces[id].list[0][i] == tidx)
                    break;
            }
            if (i == tcnt)
                return 0;
        }
        if (p == N*N)
            return 1;
        int cnt = 0, lidx = 0;
        if (p%N == 0) {
            id = P[(p/N-1)*N + 1];
            cnt = pieces[id].count[2]; //down
            lidx = 2;
        } else {
            cnt = pieces[id].count[1]; //right
            lidx = 1;
        }
        if (!cnt)
            return 0;
        for (int i =0;i<cnt;i++)
        {
            if (!V[pieces[id].list[lidx][i]]) {
                V[pieces[id].list[lidx][i]] = pieces[id].list[lidx][i];
                P[p+1] = pieces[id].list[lidx][i];
                if (findans(p+1, pieces[id].list[lidx][i]))
                    return 1;
                V[pieces[id].list[lidx][i]] = 0;
            }
        }
        return 0;
}

int findCenterPiece()
{
        int ans = 0;
        preprocess();
        for (int i=1; i<= gid; i++) {
            P[1] = i;
            V[i] = i;
            if (findans(1, i))
                break;
            V[i] = 0;
        }
        int id = P[(N*N)/2 + 1];
        for(int i = 0; i<4;i++){
            for(int j = 0;j<M;j++){
                if(pieces[id].values[i][j]==1)
                    ans++;
            }
        }
        print();
        return ans;
}

