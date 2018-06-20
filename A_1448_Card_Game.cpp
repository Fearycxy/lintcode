class Solution {
public:
    /**
     * @param n: The number of cards
     * @param totalProfit: The totalProfit
     * @param totalCost: The totalCost
     * @param a: The profit of cards
     * @param b: The cost of cards
     * @return: Return the number of legal plan
     */
    int numOfPlan(int n, int totalProfit, int totalCost, vector<int> &a, vector<int> &b) {
        // Write your code here
        const int M = 1e9 + 7;
        int dp[110][110] = {0};
        dp[0][0] = 1;
        int an = 0;
        for(int t = 0;t<n;t++){
            for(int i=totalProfit+1;i>=0;i--){
                for(int j = totalCost-1;j>=0;j--){
                    if(a[t]+i>totalProfit && b[t]+j < totalCost)
                        dp[totalProfit+1][b[t]+j] = (dp[totalProfit+1][b[t]+j] + dp[i][j])%M;
                    if(a[t] +i <= totalProfit && b[t]+j < totalCost)
                        dp[i+a[t]][b[t]+j] = (dp[i+a[t]][b[t]+j] + dp[i][j])%M;
                }
            }
        }
        for(int i = 0;i<totalCost;i++)
            an = (an + dp[totalProfit+1][i])%M;
        return an;
    }
};
