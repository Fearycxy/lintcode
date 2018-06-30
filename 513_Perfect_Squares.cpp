class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        // write your code here
        int dp[n+1] = {0};
        for(int i =1;i<n+1;i++){
            int f = INT_MAX;
            for(int j =1;j*j<=i;j++){
                f = min(f,dp[i-j*j]+1);
            }
            dp[i] = f;
        }
        return dp[n];
    }
};
