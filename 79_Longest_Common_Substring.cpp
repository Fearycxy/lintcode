class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int dp[m+1][n+1];
        int max = 0;
        memset(dp,0,sizeof(dp));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(A[i] == B[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1]>max){
                        max = dp[i+1][j+1];
                    }
                }else{
                    dp[i+1][j+1] = 0;
                }
            }
        }
        return max;
    }
};
