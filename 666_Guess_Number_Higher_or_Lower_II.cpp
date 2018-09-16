class Solution {
public:
    /**
     * @param n: An integer
     * @return: how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        // write your code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =2;i<=n;i++){
            for(int j = i-1;j>0;j--){
                int global = INT_MAX; 
                for(int k = j+1;k<i;k++){
                    int local = max(dp[j][k-1] ,dp[k+1][i]) + k;
                    global = min(global,local);
                }
                dp[j][i] = j+1==i? j:global;
            }
        }
        return dp[1][n];
    }
};
