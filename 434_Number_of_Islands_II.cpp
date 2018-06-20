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
    int* mp;
    int len = 0;
    inline void bind(int a,int b){
        if(mp[a] == -1){
             mp[a] = a;
             len++;
        }
        if(mp[b] == -1)return; 
        while(mp[a] != a) a=mp[a];
        while(mp[b] != b) b=mp[b];
        if(a == b) return;
        len--;
        mp[b] = a;
    }
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<int> an;
        mp = new int[n*m];
        fill(mp, mp + n*m, -1);
        pair<int,int> step[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &p:operators){
            int g = p.x*m+p.y;
            bind(g,g);
            for(auto &f :step){
                int k = p.x+f.first;
                int j = p.y+f.second;
                if(k<0||k>=n || j<0||j>=m) continue;
                j = k*m +j;
                bind(g,j);
            }
            an.push_back(len);
        }
        return an;
    }
};
