class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */

    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = n-1;i>=0;i--){//转递归为循环，这里要逆向
            for(int j = 0;j<=m;j++){//这个顺序没啥影响
                if(A[i]>j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = max(dp[i+1][j],A[i]+dp[i+1][j-A[i]]);
                }
            }
        }
        return dp[0][m];
    }
};
