class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        if(!m){
            return 0;
        }
        int n = grid[0].size();
         if(!n){
            return 0;
        }
        int dp[m][n]={0};
        dp[0][0] =grid[0][0];
        for(int i =1;i<m;i++){
            dp[i][0] =grid[i][0]+dp[i-1][0];
        }
         for(int i =1;i<n;i++){
            dp[0][i] =grid[0][i]+dp[0][i-1];
        }
        for(int i =1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }

//优化存储版
     int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        if(!m){
            return 0;
        }
        int n = grid[0].size();
         if(!n){
            return 0;
        }
        int dp[n]={0};
        dp[0] =grid[0][0];
         for(int i =1;i<n;i++){
            dp[i] =grid[0][i]+dp[i-1];
        }
        auto it = grid.begin();
        it++;
        for(;it !=grid.end();it++){
            for(int j = 0;j<n;j++){
                dp[j]=(j?min(dp[j-1],dp[j]):dp[j])+(*it)[j];
            }
        }
        return dp[n-1];
    }
};
