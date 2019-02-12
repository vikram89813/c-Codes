//=============================================
#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1028
extern int compare (int a,int b);

#define PRINT(a) for(int i=1;i<=N;i++) {cout<<a[i]<<" "<<"\n"[i!=N];}
char grid[MAX_SIZE+1][MAX_SIZE+1];
int N;
int query[MAX_SIZE];

//mergesort
int L[MAX_SIZE], R[MAX_SIZE];
void merge(int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;

    int i, j, k;
    for (i=0;i<n1;i++)
        L[i] = query[l+i];
    for (j=0;j<n2;j++)
        R[j] = query[mid+1+j];
    i=j=0;
    k=l;
    while (i<n1 && j<n2) {
        if (compare(L[i], R[j]))
            query[k++]=L[i++];
        else
            query[k++]=R[j++];
    }
    while (i<n1)
        query[k++]=L[i++];
    while (j<n2)
        query[k++]=R[j++];
}

void mergesort(int l, int r) {
    if (l < r) {
        int mid = l + (r-l)/2;
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, mid, r);
    }
}

void Init (int n,char map_mat[MAX_SIZE][MAX_SIZE])
{
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grid[i][j]=map_mat[i][j];
            //cout << map_mat[i][j]<< " ";
        }
        //cout << endl;
        query[i]=i;
    }
    N = n;
}

const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};
int dist[MAX_SIZE+1][MAX_SIZE+1];
typedef struct pos {
    int x, y, d;
    pos() {}
    pos(int x, int y, int d): x(x), y(y), d(d){}
} pos;
std::queue<pos>q;
void bfs(int sx, int sy)
{
    dist[sx][sy]=0;
    
    q.push(pos(sx,sy,0));
    while(!q.empty()) {
        pos p;
        p = q.front();
        //cout << p.x << p.y << p.d << endl;
        q.pop();
        for (int k=0;k<4;k++){
            int x = X[k]+p.x;
            int y = Y[k]+p.y;
            if (x >= 1 && x <= N && y >= 1 && y <= N
                && dist[x][y] == -1 && grid[x][y] == '.') {
                    dist[x][y]=p.d+1;
                    q.push(pos(x,y,p.d+1));
                }
        }
    }
}

void findresult (int x,int y,int result[MAX_SIZE/2])
{
    /* get random queries */
   // mergesort(0, N-1);
   // PRINT(query);
   auto fun = [](int a,int b){
        if(compare(a,b)) return false;
        return true;
    };

    sort(query,query+N, fun);
    //PRINT(query);
    for (int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j]=-1;
        }
    }
    /* bfs to find shortest distance from (x, y) to all points in query */
    bfs(x, y);
    #if DEBUG
    for (int i=1;i<=N;i++) {
        for (int j=1; j<=N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    int k = 0;
    for (int i=1;i<=N;i+=2){
        int tx = query[i];
        int ty = query[i+1];
        result[k++] = dist[tx][ty];
        //cout << dist[tx][ty] << " ";
    }
    //cout << endl;
}
// dist[][] = {-1};