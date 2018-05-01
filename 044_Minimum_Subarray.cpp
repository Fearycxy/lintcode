class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int tem = 0;
        int sum = nums[0];
        if(sum<0){
            tem = sum;
        }
        for(int i = 1;i<n;i++){
            int h = nums[i]+tem;
            if(h<=sum){
                sum = h;
                 if(sum<=0){
                        tem = sum;
                }
            }else{
                if(h<=0){
                tem = h;
                }else{
                    tem = 0;
                }
            }
        }
        return sum;
    }
};
