class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target && set.find(nums[left]) == set.end()) {
                set.insert(nums[left]);
                count++;
                left++;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};
