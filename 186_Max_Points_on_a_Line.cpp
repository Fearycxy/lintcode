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
    /**
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        // write your code here
        int n = points.size();
        unordered_map<float,int> mp;
        int re = 0;
        for(int i = 0;i<n;i++){
             int duplicate = 1;
             Point &p1 = points[i];
             mp.clear();
             mp[INT_MIN] = 0;
            for(int j = 0;j<n;j++){
               if(i==j) continue;
                Point &p2 = points[j];
               if(p1.x == p2.x && p1.y == p2.y){
                   duplicate++;
                   continue;
               }
                float k = p1.x == p2.x?INT_MAX: (float)(p2.y - p1.y)/(p2.x-p1.x);
                mp[k]++;
            }
            for(auto it = mp.begin();it!=mp.end();it++){
                re = max(it->second+duplicate,re);
            }
        }
        return re;
    }
};
