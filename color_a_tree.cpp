#include<bits/stdc++.h>

using namespace std;

int N,K;

vector<int> cost;
bool tree[1001][1001];

int main() {
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        int t;
        cin>>t;
        cost.emplace_back(t);
    }

    for(int i=0;i<1001;i++) {
        for(int j=0;j<1001;j++) {
            tree[i][j] = false;
        }
    }

    for(int i=0;i<N-1;i++) {
        int a,b;
        cin>>a>>b;
        tree[a][b] = true;
    }
}