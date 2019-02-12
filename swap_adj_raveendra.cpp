#include <iostream>
using namespace std;

int T;
int A[100000 + 10];
int B[100000 + 10];
int S[100000 + 10];
char str1[100000 + 10];
char str2[100000 + 10];
int len1, len2, len;
long long cnt = 0;

void update() {
    int i = 0, j = 0, k = 0;
    len1 = len2 = 0;
    while(str1[k]) {
        if(str1[k] == 'a')
            A[len1++] = k++;
        else
            B[len2++] = k++;
    }
    len = 0;
    while(str2[len]) {
        if(str2[len] == 'a')
            S[len++] = A[i++];
        else
            S[len++] = B[j++];
    }
}

void merge(int left, int right, int m)
{
    int i = 0, j = 0;
    int l = m - left + 1;
    int r = right - m;
    int *L = new int[l];
    int *R = new int[r];
    for(int k = left; k <= m;k++)
        L[i++] = S[k];
    for(int k = m+1; k <= right; k++)
        R[j++] = S[k];
    int k = left;
    i = 0; j = 0;
    while(i < l && j < r) {
        if(L[i] <= R[j])
            S[k++] = L[i++];
        else {
            cnt +=  (l - i);
            S[k++] = R[j++];
        }
    }
    while(i < l)
        S[k++] = L[i++];
    while(j < r)
        S[k++] = R[j++];
    delete L, R;
}


void mergesort(int l, int r)
{
    if(l < r) {
        int mid = l + (r - l) / 2;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, r, mid);
    }
}

int getSwapCount() {
    cnt = 0;
    if(len != len1 + len2)
        return -1;
    mergesort(0, len - 1);
    return cnt;
}

int main() {
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> str1 >> str2;
        update();
        cout << "#" << tc << " " << getSwapCount() << endl;
    }
    return 0;
}

