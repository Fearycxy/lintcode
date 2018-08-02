class Solution {
public:
    /**
     * @param height: the given height
     * @param width: the given width
     * @return: the number of paths you can reach the end
     */
    int uniquePath(int height, int width) {
        // Write your code here
        // vector<vector<long long>> dp(height+2, vector<long long>(width, 0));
        // vector<vector<long>> dp(height+2, vector<long>(width, 0));
        long long dp[height+2][width];
        memset(dp, 0, sizeof(long long)*(height+2)*width);
        dp[1][0] = 1;
        long long MOD = 1000000007;
        for(int i=1; i<=width; i++){
            // i-th column
            for(int j=1; j<=height; j++){
                // j-th row
                dp[j][i] = dp[j-1][i-1] + dp[j][i-1] + dp[j+1][i-1];
                dp[j][i] %= MOD;
            }
        }
        return dp[1][width-1];
    }
};
