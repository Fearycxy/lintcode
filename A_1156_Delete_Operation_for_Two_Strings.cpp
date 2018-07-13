class Solution {
public:
    /**
     * @param word1: a string
     * @param word2: a string
     * @return: return a integer
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int m = word1.size(),n = word2.size();
        int dp[m+1][n+1];
        memset(dp,0x0, sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n - 2* dp[m][n];
    }
};
