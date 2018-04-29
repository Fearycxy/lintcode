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
        int dp[2][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=m;j++){
                if(A[i]>j){
                    dp[(i+1)%2][j] = dp[i%2][j];
                }else{
                    dp[(i+1)%2][j] = max(dp[i%2][j],A[i]+dp[i%2][j-A[i]]);
                }
            }
        }
        return dp[n%2][m];//前n个和不超过m的最大
    }
};
