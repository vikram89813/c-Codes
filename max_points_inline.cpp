/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& arr) {
        map<pair<int,int>,int> h;
        int n = arr.size();
        if(n==1) return 1;
        //if(n<=2) return n;
        int ans = 0;
        for(int i=0;i<n;i++){
            h.clear();
            int dub=1;
            for(int j=i+1;j<n;j++) {
                if(arr[j].x == arr[i].x && arr[j].y==arr[i].y) {
                    dub++;
                    continue;
                }
                int dx = arr[j].x - arr[i].x;
                int dy = arr[j].y - arr[i].y;
                int gc = gcd(dx,dy);

                h[make_pair(dx/gc,dy/gc)]++;
            }
            ans = max(ans,dub);

                for(auto val : h) {
                    if((val.second + dub) > ans)
                        ans = val.second + dub;
                }
        }
        return ans;
    }
    
    int gcd(int a,int b) {
        if(!b) return a;
        return gcd(b,a%b);
    }
};