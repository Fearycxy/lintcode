class Solution {
public:
    /**
     * @param grid: a 2D array
     * @return: the perimeter of the island
     */
    int islandPerimeter(vector<vector<int>> &grid) {
        // Write your code here
        int an= 0 ,m = grid.size(),n=grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(!grid[i][j]) continue;
                if(i==0 || !grid[i-1][j]) an++;
                if(i==m-1 || !grid[i+1][j]) an++;
                if(j==0 || !grid[i][j-1]) an++;
                if(j==n-1 || !grid[i][j+1])an++;
            }
        }
        return an;
        
    }
};
