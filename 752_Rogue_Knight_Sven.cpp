class Solution {
public:
    /**
     * @param n: the max identifier of planet.
     * @param m: gold coins that Sven has.
     * @param limit: the max difference.
     * @param cost: the number of gold coins that reaching the planet j through the portal costs.
     * @return: return the number of ways he can reach the planet n through the portal.
     */
    long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
        long long dp[n+1][m+1] , re = 0;
        memset(dp,0,sizeof(dp));
        dp[0][m] = 1;
        for(int i=1;i<=n;i++){
            for(int t=i-1;t>=max(0,i-limit);t--){
                for(int j = 0;j<=m-cost[i];j++){
                    dp[i][j] += dp[t][j+cost[i]];
                }
            }
        }
        for(int i=0;i<=m;i++) re += dp[n][i];
        return re;
    }
};
