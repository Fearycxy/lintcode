class Solution {
public:
    /**
     * @param point: a list of two-tuples
     * @return: a boolean, denote whether the polygon is convex
     */
    bool isConvex(vector<vector<int>> &point) {
        // write your code here
        long long n = point.size(),pre = 0,cur = 0;
        for(long long i = 0;i<n;i++){
            int x1 = point[(i+1)%n][0] - point[i][0];
            int y1 = point[(i+1)%n][1] - point[i][1];
            int x2 = point[(i+2)%n][0] - point[i][0];
            int y2 = point[(i+2)%n][1] - point[i][1];
            cur = x1*y2-x2*y1;//叉乘计算法向量方向
            if(cur != 0){
                if(cur*pre<0) return false;
                pre = cur;
            }
        }
        return true;
    }
};
