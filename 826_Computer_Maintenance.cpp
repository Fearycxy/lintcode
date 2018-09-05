class Solution {
public:
    /**
     * @param n: the rows of matrix
     * @param m: the cols of matrix
     * @param badcomputers: the bad computers
     * @return: The answer
     */
    int maintenance(int n, int m, vector<Point> badcomputers) {
        // Write your code here
        vector<pair<int, int>> vec(n,{m - 1, 0});
        int dp[n][2] = {0};
        for (auto &p:badcomputers) {
            vec[p.x].first = min(p.y, vec[p.x].first);
            vec[p.x].second = max(p.y, vec[p.x].second);
        }
        dp[0][0] = vec[0].second << 1;
        dp[0][1] = m-1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0] + 1 + 2 * vec[i].second, dp[i - 1][1] + m);
            dp[i][1] = min(dp[i - 1][0] + m, dp[i - 1][1] + 1 + 2 * (m - 1 - vec[i].first));
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};
