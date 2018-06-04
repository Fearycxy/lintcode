class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int x =0;int y = nums.size()-1;
        while(x < y){
            while(x<y && nums[x] &1) x++;
            while(x<y && (nums[y]&1) == 0) y--;
            if(x<y ) swap(nums[x++],nums[y--]);
        }
    }
};
