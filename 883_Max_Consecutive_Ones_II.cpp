class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        int ans = 0, cur = 0 , pre = 0;
        for(int i:nums){
            if(i){
                cur++;
            }else{
                ans = max(ans,pre+cur);
                pre = cur+1;
                cur = 0;
            }
        }
        return ans;
    }
};
