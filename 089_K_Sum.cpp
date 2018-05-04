class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
     
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int n = A.size();
       int dp[n+1][k+1][target+1];
       memset(dp,0,sizeof(dp));
       for(int i =0;i<n+1;i++){
           dp[i][0][0]=1;
       }
     
       for(int i =1;i<n+1;i++){
         for(int j = 1;j<min(k+1,i+1);j++){
             for(int l=1;l<=target;l++){
                 if(l-A[i-1]>=0){
                 dp[i][j][l] = dp[i-1][j][l]+dp[i-1][j-1][l-A[i-1]];
                 }else{
                    dp[i][j][l] = dp[i-1][j][l]; 
                 
                 }
             }
         }  
       }
        return dp[n][k][target];
    }
//优化存储空间
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        if (target < 0) {
            return 0;
        }
        int len = A.size();
        int dp[k+1][target+1] ;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            for (int j = k; j >= 1; j--) {
                for (int t = 0; t <=target; t++) {
                    if (t - A[i - 1] >= 0) {
                        dp[j][t] += dp[j - 1][t - A[i - 1]];
                    }
                }
            }
        }
        return dp[k][target];
    }
};
