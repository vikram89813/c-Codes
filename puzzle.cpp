#pragma GCC optimize ("-Ofast")
int N, M, K;

struct piece {
    int list[4][6]; // 0-top, 1-right, 2-down, 3-left
    int count[4];
    int sig[4];
    int values[4][15+1];
};
typedef struct piece piece;

piece pieces[49*49 + 10];
int gid;
int topleft[6];
int tcount;
int V[49*49 + 10];
int P[49*49 + 10];

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
    }
}

void updatematch(int a, int b){
    //CHK
    for (int i = 0;i < 4; i++)
    {
        if (pieces[a].sig[i]==pieces[b].sig[i^2]) {
            int j;
            for (j = 0; j<M; j++) {
                if (pieces[a].values[i][j] + pieces[b].values[i^2][j] != 0)
                    break;
            }
            if (j == M) {
                int cnt = pieces[a].count[i];
                pieces[a].list[i][cnt] = b;
                pieces[a].count[i] = ++cnt;
            }
        }
    }
}

void preprocess()
{
    for (int i = 1; i <= gid; i++) {
        for (int j = 1; j<= gid; j++){
            if (i != j) {
                updatematch(i, j);
            }
        }
    }

    for(int i =1; i<=gid; i++) {
        if(!pieces[i].count[0] && !pieces[i].count[3])
            topleft[tcount++] = i;
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
        for (int i=0; i< tcount; i++) {
            P[1] = topleft[i];
            V[topleft[i]] = topleft[i];
            if (findans(1, topleft[i]))
                break;
            V[topleft[i]] = 0;
        }
        int id = P[(N*N)/2 + 1];
        for(int i = 0; i<4;i++){
            for(int j = 0;j<M;j++){
                if(pieces[id].values[i][j]==1)
                    ans++;
            }
        }
        return ans;
}

