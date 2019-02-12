#include <stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
    int tc, T, C[100001], c, i, N;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (i = 0; i < 100001; C[i++] = 0){}
        while (N--) {
            scanf("%d", &c);
            C[c]++;
        }
        c = N = 0;
        for (i = 100000; i; i--) {
            while (C[i]) {
                N++;
                C[i]--;
                cout<<N<<" "<<i<<endl;
                if (N % 3)  {
                    cout<<"inside "<<N<<" "<<i<<endl;
                    c += i;
                }
                cout<<"==================="<<endl;
            }
        }
        printf("#%d %d\n", tc, c);
    }
    return 0;
}

