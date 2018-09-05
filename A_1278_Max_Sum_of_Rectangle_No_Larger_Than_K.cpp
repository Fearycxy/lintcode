class Solution {
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        // Write your code here
        if(matrix.empty()) return 0;
        int m=matrix.size(),n = matrix[0].size(),an = INT_MIN;
        int dp[m+1][n+1] = {0};
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
                for(int p = 0;p<=i;p++){
                    for(int q = 0;q<=j;q++){
                        int s = dp[i+1][j+1] + dp[p][q] - dp[p][j+1] - dp[i+1][q];
                        if(s <= k && s > an) an = s;
                        if(an == k) return k;
                    }
                }
            }
        }
        return an;
    }
};
