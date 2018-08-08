class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int n = A.size();
        int dp[m+1] ={0};
        for(int i =0;i<n;i++){
            for(int j = A[i];j<=m;j++){
                dp[j] = max(dp[j] ,dp[j-A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};
