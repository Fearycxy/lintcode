class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
       int m = A.size();
       int n = B.size();
        if(n == 0 || m == 0){
           return 0;
       }
       int dp[m+1][n+1];
       for(int i =0;i<m+1;i++){
           dp[i][0] = 0;
       }
        for(int i =0;i<n+1;i++){
           dp[0][i+1] = 0;
       }
       for(int i = 0;i<m;i++){
          for(int j = 0;j<n;j++){
              if(A[i] == B[j]){
                  dp[i+1][j+1] = dp[i][j] +1;
              }else{
                  dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
              }
          }
       }
       return dp[m][n];
    }
};
