class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        int dp[n][100];//第i位取值为j时前i为的diff最小值
        int re = INT_MAX;
        for(int i =0;i<n;i++){
            for(int j =1;j<=100;j++){
                dp[i][j-1] = INT_MAX;
                if(i==0){
                    dp[i][j-1] = abs(j-A[0]);
                }else{
                    int dif;
                    for(int k = 1;k<=100;k++){//对前一位的取值进行遍历
                        if(abs(j-k)>target){
                            continue;
                        }
                        dif =abs(j-A[i])+dp[i-1][k-1];
                        dp[i][j-1] = min(dif,dp[i][j-1]);
                    }
                }
                if(i==n-1){
                     re = min(re,dp[i][j-1]);
                }
            }
        }
        return re;
    }
};
