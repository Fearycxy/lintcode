class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() -1, re = 0;
        while(left < right){
            if(nums[left] + nums[right] > target) re+= right-- -left;
            else left++;
        }
        return re;
    }
};
