class Solution {
public:
    /**
     * @param strs: an array with strings include only 0 and 1
     * @param m: An integer
     * @param n: An integer
     * @return: find the maximum number of strings
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        // write your code here
        int dp[m+1][n+1];// for dp[i][j] ,means i 0s  j 1s how many strings we can formed 
        memset(dp, 0, sizeof(dp));
        dp[0][0] =1;
        int an = 0;
        for(string &s:strs){
            int a = 0 ,b = 0;
            for(char c:s){
                if(c=='0') a++;
                else b++;
            }
            for(int i=m;i>=a;i--){
                for(int j = n;j>=b;j--){
                    if(dp[i-a][j-b])dp[i][j]=max(dp[i][j],dp[i-a][j-b] +1);
                    an = max(an,dp[i][j]);
                }
            }
        }
        if(!an) return 0;
        return an-1;
    }
};
