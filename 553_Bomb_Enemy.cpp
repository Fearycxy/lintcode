//第二重做版，果然，第一遍的代码还是丑呀
class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if(grid.empty()) return 0;
        int m = grid.size(),n = grid[0].size(),an = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            int j = 0 ,last = 0;
            while(j<n){
                int cur = 0;
                while(j<n && grid[i][j] != 'W'){
                    if(grid[i][j++] == 'E')cur++;
                }
                for(;last<j;last++){
                    dp[i][last] = cur;
                }
                last = ++j;
            }
        }
        for(int i = 0;i<n;i++){
            int j = 0 ,last = 0;
            while(j<m){
                int cur = 0;
                while(j<m && grid[j][i] != 'W'){
                    if(grid[j++][i] == 'E')cur++;
                }
                for(;last<j;last++){
                    if(grid[last][i] == 'E') continue;
                    int g= grid[last][i] == 'E' ? -1 : 0;
                    an = max(an, dp[last][i] + cur+g);
                }
                last = ++j;
            }
        }
        return an;
    }
};


//version 1
class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        vector<vector<int>> a(m,vector<int>(n,0)),b=a,c=a,d=a;
        for(int i =0 ;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j] = (!j || grid[i][j] == 'W') ?0:a[i][j-1];
                if(grid[i][j] == 'E') a[i][j]++;
            }
            for(int j=n-1;j>=0;j--){
                b[i][j] = (j==n-1 || grid[i][j] == 'W') ?0:b[i][j+1];
                if(grid[i][j] == 'E') b[i][j]++;
            }
        }
        for(int j =0 ;j<n;j++){
            for(int i=0;i<m;i++){
                c[i][j] = (!i || grid[i][j] == 'W') ?0:c[i-1][j];
                if(grid[i][j] == 'E') c[i][j]++;
            }
            for(int i=m-1;i>=0;i--){
                d[i][j] = (i==m-1 || grid[i][j] == 'W') ?0:d[i+1][j];
                if(grid[i][j] == 'E') d[i][j]++;
            }
        }
        int an =0;
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == '0')
                    an = max(an,a[i][j]+b[i][j]+c[i][j]+d[i][j]);
            }
        }
        return an;
    }
};
