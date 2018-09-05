class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        // Write your code here
        int left = 0, right = nums.size()-1;
        while(left < right-1){
            int mid = (right-left) /2  + left;
            int h = mid+1;
            if(mid&1) h = mid-1;
            if(nums[h]==nums[mid]) left = max(mid,h)+1;
            else right = max(mid,h);
        }
        return nums[left];
    }
};
