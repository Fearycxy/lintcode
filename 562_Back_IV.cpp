class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int dp[target+1] ={0};
        dp[0] = 1;
        for(int p:nums){
            for(int i = p;i<=target;i++){
                dp[i] += dp[i-p];
            }
        }
        return dp[target];
    }
};
