class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        bool dispose = false;
        for(int i =n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                dispose = true;
                for(int y = n-1;y>=i;y--){
                    if(nums[y]>nums[i-1]){
                        swap(nums[y],nums[i-1]);
                        break;
                    }
                }
                reverse(nums.data()+i,nums.data()+n);
                break;
            }
        }
        if(!dispose){
            reverse(nums.begin(),nums.end());
        }
        return nums;
    }
    
};
