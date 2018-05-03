class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2;i<n;i++){
            dp[i%2] = dp[0]+dp[1];
        }
        return dp[(n-1)%2];
        // write your code here
    }
};
