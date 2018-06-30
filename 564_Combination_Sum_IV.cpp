//排列还是比组合简单多了
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        int dp[target+1] ={0};
        dp[0] =1;
        for(int i=1;i<=target;i++){
            for(int y:nums){
                if(i-y>=0){
                    dp[i]+= dp[i-y];
                }
            }
        }
        return dp[target];
    }
};
