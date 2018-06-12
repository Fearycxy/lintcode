class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>> &A) {
        // write your code here
        if(A.empty() || A[0].empty()) return 0;
        int n = A.size(),m = A[0].size(),re = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i =0;i<n;i++)
            for(int j = 0;j<m;j++)
                re = max(re, dfs(i,j,A,dp));
        return re;        
    }
    
    int dfs(int i,int j,vector<vector<int>> &A,vector<vector<int>> &dp){
        if(dp[i][j]) return dp[i][j];
        pair<int,int> step[4] = {{0,-1},{-1,0},{1,0},{0,1}};
        for(auto p:step){
            int px = i+p.first;
            int py = j+p.second;
            if(px>=0&&px<A.size()&&py>=0&&py<A[0].size()&&A[px][py] < A[i][j]){
                dp[i][j] = max(dfs(px,py,A,dp),dp[i][j]);
            }
        }
        return ++dp[i][j];
    }
};
