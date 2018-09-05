class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() -1, re = INT_MAX;
        while(left < right){
            if(nums[left] + nums[right]  == target) return 0;
            else {
                re = min((int)abs(nums[left]+nums[right] -target),re);
                if(nums[left] + nums[right] > target) right--;
                else left++;
            }
        }
        return re;
    }
};
