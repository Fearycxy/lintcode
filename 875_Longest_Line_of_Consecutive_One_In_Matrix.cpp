class Solution {
public:
    /**
     * @param M: the 01 matrix
     * @return: the longest line of consecutive one in the matrix
     */
    int longestLine(vector<vector<int>> &M) {
        // Write your code here
        if(M.empty()) return 0;
        int m = M.size(), n =M[0].size(), re = 0 ;
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(4)));
        vector<vector<int>> step = {{1,0},{0,1},{0,0},{0,2}};
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                bool one = M[i][j] == 1;
                for(int t=0;t<3;t++){
                    dp[i+1][j+1][t] = one?dp[i+step[t][0]][j+step[t][1]][t] +1:0;
                    re = max(re,dp[i+1][j+1][t]);
                }
            }
        }
        return re;
    }
};
