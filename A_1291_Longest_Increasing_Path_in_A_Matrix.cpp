class Solution {
public:
vector<vector<int>> step ={{0,1},{1,0},{-1,0},{0,-1}};
int m;
int n;
    /**
     * @param matrix: an integer matrix
     * @return: the length of the longest increasing path
     */
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        // write your code here
        if(matrix.empty()) return 0;
        m = matrix.size();n = matrix.back().size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        int re = 1;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                dfs(dp,re,i,j,matrix);
            }
        }
        return re;
    }
    
    void dfs(vector<vector<int>> &dp,int &re,int i,int j,vector<vector<int>> &matrix){
        for(auto s:step){
            int x = i + s[0];
            int y = j + s[1];
            if(x>=0 && x<m && y>=0 && y<n && matrix[x][y] < matrix[i][j] &&dp[x][y] < dp[i][j] +1){
                dp[x][y] = dp[i][j] + 1;
                re = max(re,dp[x][y]);
                dfs(dp,re,x,y,matrix);
            }
        }
    }
};
