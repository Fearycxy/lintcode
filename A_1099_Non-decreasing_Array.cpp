class Solution {
public:
    /**
     * @param nums: an array
     * @return: if it could become non-decreasing by modifying at most 1 element
     */
    bool checkPossibility(vector<int> &nums) {
        // Write your code here
        bool modified = false;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                if(modified) return false;
                else {
                     modified = true;
                    if(i!=1 && nums[i-2] > nums[i]) nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};
