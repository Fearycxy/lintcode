class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.empty()) return 0;
        int re = 0;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    re++;
                    dfs(grid,i,j);
                }
            }
        }
        return re;
    }
    void dfs(vector<vector<bool>> & grid,int i,int j){
        grid[i][j]=0;
        pair<int,int> step[4]={{0,1},{0,-1},{-1,0},{1,0}};
        for(auto p:step){
            int mx = i+p.first;
            int my = j+p.second;
            if(mx>=0&&mx<grid.size() && my>=0&& my<grid[0].size()&& grid[mx][my]){
                dfs(grid,mx,my);
            }
        }
    }
};
