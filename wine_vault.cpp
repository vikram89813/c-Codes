#include<bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <string.h>

typedef unsigned int uint;
static uint seed;
static uint mrand(uint num)
{
    seed = seed * 1103515245 + 37209;
    return ((seed >> 8) % num);
}

#define MAX_BARRELS 1000000

void init();
void put(int mark);
int get();

int test_random()
{
    long long int s = 0;
    long long int correct;
    int n, mark, range, cnt = 0;

    scanf("%u %i %i", &seed, &n, &range);

    init();

    for (int i = 0; i < n; ++i)
    {
        int cmd = mrand(3);

        if (cnt == MAX_BARRELS) cmd = 0; // get
        else if (cnt == 0) cmd = 1; // put

        if (cmd == 0)
        {
            mark = get();
            s += mark;
            --cnt;
        }
        else
        {
            mark = mrand(range);
            put(mark);
            ++cnt;
        }
    }

    scanf("%lli", &correct);
    return s == correct;
}

bool test_manual()
{
    int correct;
    char cmd[16];
    bool ok = true;
    int mark;

    init();

    while (true)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "put"))
        {
            scanf("%i", &mark);
            put(mark);
        }
        else if (!strcmp(cmd, "get"))
        {
            mark = get();
            scanf("%i", &correct);
            if (mark != correct) ok = false;
        }
        else
            break;
    }
    return ok;
}

bool test()
{
    char method[16];
    scanf("%s", method);
    if (!strcmp(method, "[RND]"))
        return test_random();
    else if (!strcmp(method, "[MAN]"))
        return test_manual();
    printf("Error\n");
    return false;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input_wine", "r", stdin);
    int ntests = 0;
    scanf("%i", &ntests);
    for (int t = 1; t <= ntests; ++t)
    {
        printf("#%i %i\n", t, test() ? 100 : 0);
    }
    return 0;
}


//===============================
map<int,int> h;

int ans;
int count;
void init() {
    h.clear();
    ans = -1;
    count = -1;
}

void put(int v) {
    h[v]++;
    if(h[v] > count){
        count = h[v];
        ans = v;
    }
}

int get() {
    int t = ans;
}
