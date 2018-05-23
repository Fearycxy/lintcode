class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int n =nums.size();
        if(n<2) return;
        for(int i = n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                for(int j = n-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        reverse(nums.begin()+i,nums.end());
                        return;
                    }
                }
                
            }
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};
