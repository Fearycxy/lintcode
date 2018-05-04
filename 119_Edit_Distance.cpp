class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int l1 = word1.size();
        int l2 = word2.size();
        int dp[l1+1][l2+1];
        dp[0][0]=0;
        for(int i =1;i<=l1;i++){
            dp[i][0] = i;
        }
        for(int j =1;j<=l2;j++){
            dp[0][j] = j;
        }
        for(int i = 1;i<=l1;i++){
            for(int j = 1;j<=l2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
                }
            }
        }
        return dp[l1][l2];
    }
};


//这个证明了没有啥相邻转换的dp方程不能用滚动数组来代替
class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int l1 = word1.size();
        int l2 = word2.size();
        int dp[l2+1];
        for(int j =0;j<=l2;j++){
            dp[j] = j;
        }
        int old = 0;
        int tem = 0;
        for(int i = 1;i<=l1;i++){
            old = i-1;
            dp[0] = i;
            for(int j = 1;j<=l2;j++){
                tem = dp[j];
                if(word1[i-1]==word2[j-1]){
                    dp[j] = old;
                }else{
                    dp[j] = min(min(dp[j-1],dp[j]),old)+1;
                }
                old = tem;
            }
        }
        return dp[l2];
    }
};
