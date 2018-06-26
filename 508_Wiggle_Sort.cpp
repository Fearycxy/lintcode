class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(((i & 1) == 1  && nums[i] < nums[i-1])
            ||((i & 1) == 0  && nums[i] > nums[i-1]) ) swap(nums[i],nums[i-1]);
        }
    }
};
