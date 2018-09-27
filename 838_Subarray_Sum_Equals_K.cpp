class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        int res=0, sum=0;
        unordered_map<int,int> mp{{0,1}};
        for(int i=0; i<nums.size(); ++i) {
            sum+=nums[i];
            res+=mp[sum-k];
            ++mp[sum];
        }
        return res;
    }
};
