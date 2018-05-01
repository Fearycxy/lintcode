class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        bool ischoose = false;
        for(int i =n-1;i>=1;i--){
            if(nums[i]<nums[i-1]){
                ischoose = true;
                reverse(nums.data()+i,nums.data()+n);
                int y = n-1;
                for(y = i;y<=n-1;y++){
                    if(nums[y]<nums[i-1]){
                        break;
                    }
                }
                swap(nums[i-1],nums[y]);
                break;
            }
        }
        if(!ischoose){
            reverse(nums.begin(),nums.end());
        }
        return nums;
    }
};
