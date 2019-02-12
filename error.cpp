#include <bits/stdc++.h>
using namespace std;

class compare {
    public:
    bool operator() (int& e1, int &e2) {
        return e1 >= e2;
    }
};

int main() {

    //std::vector<int> nums1 = {1, 3};
    //std::vector<int> nums2 = {2};

    priority_queue<int, vector<int>, compare> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);

    int ans = 0;
    for (int i=0; i<3; i++) {
        ans = std::max((int)pq.size(), ans);
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
