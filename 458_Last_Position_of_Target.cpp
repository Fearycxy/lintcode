class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        int left =0,right = nums.size();
        while(left < right-1){
            int mid = (left+right) >> 1;
            if(nums[mid] <= target) left = mid;
            else right = mid;
        }
        if(!right || nums[left] != target) return -1;
        return left;
    }
}

//version 2 :
class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        auto y = upper_bound(nums.begin(),nums.end(),target);
        if(y == nums.begin() || *(y-1) != target){
            return -1;
        }
        return y - nums.begin()-1;
    }
};
