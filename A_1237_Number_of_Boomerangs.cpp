class Solution {
public:
    /**
     * @param points: a 2D array
     * @return: the number of boomerangs
     */
    int numberOfBoomerangs(vector<vector<int>> &points) {
        // Write your code here
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> disCount;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                disCount[getDistance(points[i], points[j])]++;
            }
            for (auto iter = disCount.begin(); iter != disCount.end(); iter++) {
                ans += iter->second * (iter->second - 1);
            }
        }
        return ans;
    }
private:
 inline int getDistance(vector<int> &a, vector<int> &b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};
    
    
