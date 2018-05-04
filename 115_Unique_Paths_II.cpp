class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
         int m =obstacleGrid.size();
         int n = obstacleGrid[0].size();
        // write your code here
        int dp[n];
        bool flag = false;
       for(int i = 0;i<n;i++){
           if(obstacleGrid[0][i]){
               flag =true;
           }
           dp[i] =flag?0:1;
       }
        for(int i =1;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j]){
                    dp[j]=0;
                }else if(j){
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};
