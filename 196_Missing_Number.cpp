class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        for(int i =0;i<n;i++){
            while(nums[i]!=i && nums[i]!=n){
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]==n){
                return i;
            }
        }
        return n;
    }
};
