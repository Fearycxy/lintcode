class Solution {
public:
    /**
     * @param n: an integer
     * @return: return an integer
     */
    int checkRecord(int n) {
        // write your code here
        const int M = 1000000007;
        vector<vector<int>> dp(3,vector<int>(2,0));
        dp[0][0] =1;
        for(int i =1;i<=n;i++){
            auto tem = dp;
            for(int j=2;j>0;j--)
                for(int t=0;t<2;t++)
                    dp[j][t] = tem[j-1][t];
            dp[0][0] = ((dp[0][0] + tem[1][0]) %M + tem[2][0])%M;
            dp[0][1] = ((dp[0][0] +dp[0][1])%M+(tem[1][1] + tem[2][1])%M)%M;  
        }
        int an = 0;
        for(auto &y:dp)
            for(int k:y)
                an= (an + k)%M;
        return an;        
    }
};
