#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]<0 || nums[i]>=n)
            nums[i]=0;
        }
        for (int i = 0; i < n; ++i) {
            nums[nums[i]%n] += n;
        }
        for (int i = 1; i < n; ++i) {
            if (!nums[i]/n)
            return i;
        }
        return n;
    }
};
    
int main() {
    vector<int> arr = {-4,24,32,25,16,-8,3,-5,-6,30,3,3,29,-5,6,-3,1,29,-2,4,4,7,14,20,5,0,25,2,13,26,-9,7,6,33};
    Solution s;
    int sol = s.firstMissingPositive(arr);
    cout<<sol<<endl;
}