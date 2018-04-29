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
        int dp[m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++){
            for(int j = m;j>=0;j--){//因为取的是左上角的上一轮的值，逆序可以在更新左边之前先利用，反之如果不逆序则表示之前的可以再利用，则为完全背包问题
                if(A[i]<=j){
                    dp[j] = max(dp[j],A[i]+dp[j-A[i]]);
                }
            }
        }
        return dp[m];//不超过m的最大
    }
};
