class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        // write your code here
        int n =s.size();
        int dp[n+1];
        for(int i = 0;i<=n;i++){
            dp[i] = n-i;
        }
        bool matrix[n][n]={0};
        for(int i=n-1;i>=0;i--){
            for(int j =i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || matrix[i+1][j-1])){
                    matrix[i][j] = true;
                    dp[i] =min(dp[j+1]+1,dp[i]);
                }
            }
        }
        return dp[0]-1;
    }
};
