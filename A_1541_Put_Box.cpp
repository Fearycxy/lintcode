class Solution {
public:
    /**
     * @param box: the boxes
     * @param position: the positions
     * @return:  the maximum number of boxes you can put in
     */
    int putBox(vector<int> &box, vector<int> &position) {
        // Write your code here
        int m = box.size();
        int n = position.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1] = max(dp[i + 1][j], dp[i][j + 1]);
                if(box[i] <= position[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                }
                
            }
        }
        return dp[m][n];
    }
};
