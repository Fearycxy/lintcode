class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here
        for(int j=0;j<nums.size();j++)
            while(nums[nums[j]-1] != nums[j]) 
                swap(nums[j],nums[nums[j]-1]);
        return nums.back();
    }
};
