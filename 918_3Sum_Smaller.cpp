class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(),nums.end());
        int res = 0,n=nums.size();
        for(int i=0;i<n-2;i++){
            int left = i+1,right = n-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right] <target){
                    res+=right-left;//point
                    left++;
                }else{
                    right--;
                }
            }
        }
        return res;
    }
};
