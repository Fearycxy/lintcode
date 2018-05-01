class Solution {
public:

    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
  int maxSubArray(vector<int> &nums, int k) {
    // write your code here
    int n = nums.size();
    int count[n+1][k+1];
    int global[n+1][k+1];
    memset(global,0,sizeof(global));
    for(int j = 1;j<=k;j++){
        count[j-1][j] = INT_MIN;
        for(int i = j;i<=n;i++){
            count[i][j] = max(global[i-1][j-1],count[i-1][j])+nums[i-1];
            if(i==j){//非常关键
                 global[i][j] = count[i][j];
            }else{
                  global[i][j] = max(global[i-1][j],count[i][j]);
            }
        }
    }
    return global[n][k];
}
};
