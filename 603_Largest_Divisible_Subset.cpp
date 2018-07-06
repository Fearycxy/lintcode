class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        int n = nums.size(),mx = 0, mx_idx = 0;
        int dp[n] = {0};
        int parent[n] = {0};
        for(int i = n-1;i>=0;i--){
            for(int j =i;j<n;j++){
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j] +1){
                    dp[i] = dp[j] +1;
                    parent[i] = j;
                    if(dp[i] > mx){
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        vector<int> res;
         for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
};
