class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    // http://fisherlei.blogspot.com/2017/08/leetcode-maximum-length-of-pair-chain.html
    int maxCoins(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector(n+2,0));
        for(int len =1;len<=n;len++){//这里选择从长度dp很巧
            for(int l = 1;l<=n-len+1;l++){
                int r = l+len-1;
                for(int k =l;k<=r;k++){
                    dp[l][r] = max(dp[l][r],dp[l][k-1]+dp[k+1][r]+nums[k]*nums[l-1]*nums[r+1]);
                }
            }
        }
        return dp[1][n];
    }
};
