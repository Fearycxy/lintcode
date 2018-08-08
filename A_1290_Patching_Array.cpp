class Solution {
public:
    /**
     * @param nums: an array
     * @param n: an integer
     * @return: the minimum number of patches required
     */
    int minPatches(vector<int> &nums, int n) {
        // Write your code here
        long long  miss = 1,res = 0, i =0;
        while(miss <= n){
            if(i<nums.size() && nums[i] <= miss){
                miss += nums[i++];//important
            }else{
                miss += miss;
                res++;
            }
        }
        return res;
    }
};
