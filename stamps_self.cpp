#pragma GCC optimize ("-Ofast")

struct node {
  int x,y,cnt;
  node *next;
};

struct stamp {
  int s,cnt;
  char a[100][100];
  node *list;
};

struct trie {
  int id,eos;
  trie *a[10];
};

int N;
stamp stamps[105];
node lists[20005];
trie tries[100 * 5 + 5];
int tlen,gid,llen;

trie t;

void addid(trie *tr, int id) {
  while(id) {
    if(!tr->a[id%10]) {
      trie *tmp = &tries[tlen++];
        for(int i=0;i<10;i++) tmp->a[i] = 0;
        tmp->id =0;
        tmp->eos = 0;
        tr->a[id%10] = tmp;
    }
    tr = tr->a[id%10];
    id = id/10;
  }
  tr->id = gid;
  tr->eos = 1;
}

int get_id(trie *tr,int id) {
  while(tr && id) {
    if(tr->a[id%10]) {
      tr=tr->a[id%10];
      id = id/10;
    } else break;
  }
  if(!tr) return 0;
  return (tr->eos == 1 ? tr->id : 0);
}

void init(int n) {
  N = n;
  for(int i=1;i<=gid;i++)
    stamps[i].list = 0;

  gid=tlen=llen = 0;

  t = tries[tlen++];
  for(int i =0;i<10;i++)
    t.a[i] = 0;

  t.eos = 0;
  t.id = 0;
}

void addStamp(int id, int M, char pattern[100][100]) {
  ++gid;
  addid(&t,id);
  stamp *tmp = &stamps[gid];
  for(int i =0;i<M;i++)
    for(int j=0;j<M;j++)
      tmp->a[i][j] = pattern[i][j];

  tmp->cnt = 0;
  tmp->s= M;
}

void press(int id, int x, int y) {
  int lid = getid(&t,id);
  node *nd = &lists[llen++];
  nd->x = y;
  nd->y = x;
  nd->cnt = stamps[lid].cnt;
  nd->next = stamps[lid].list;
  stamps[lid].list = nd;
  stamps[idx].cnt  = (stamps[lid].cnt + 1) % 4;
}

void erase(int id) {
    int idx = getid(&t, id);
    if(idx)
        stamps[idx].list = 0;
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
            cnt = lst->dir;
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






















