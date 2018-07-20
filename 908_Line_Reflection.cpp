class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> points) {
        // Write your code here
        int xa = INT_MIN, xi = INT_MAX;
        for (auto pt:points) {
            xa = max(pt[0], xa);
            xi = min(pt[0], xi);
        }
        int xm = xa + xi, i = 1, j = points.size() - 2;
        sort(points.begin(), points.end(), [&xm](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) {
                if (v1[0] > xm) return v1[1] > v2[1];
                else return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        });
        while (i <= j) {
            if (points[i][0] + points[j][0] != xm)return false;
            if (points[i][1] != points[j][1]) return false;
            i++;j--;
        }
        return true;
    }
};
