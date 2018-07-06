class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        for(int i =0;i<n;i++){
            while(nums[nums[i]-1] != nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        vector<int> an;
        for(int i=0;i<n;i++){
            if(i != nums[i]-1) an.push_back(i+1);
        }
        return an;
    }
};
