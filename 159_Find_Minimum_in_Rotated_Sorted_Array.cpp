class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int start = 0;
        int end = nums.size()-1;
        if(nums[0]<nums[end]) return nums[0];
        while(start <end){
            int mid = (start+end)>>1;
            if(nums[mid]<nums[end]){
                end = mid;
            }else if(mid>start){
                start = mid;
            }else{
                return nums[end];
            }
        }
        return nums[end];
    }
};
