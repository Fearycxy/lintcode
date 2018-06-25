class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int waysNCents(int n) {
        // write your code here
        int dp[n+1]={0};
        dp[0] = 1;
        int y[4] = {1,5,10,25};
        for(int i =0;i<4;i++){//循环放外面很重要
            for(int j =y[i];j<=n;j++){
                dp[j] += dp[j-y[i]];
            }
        }
        return dp[n];
    }
};
