class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        // Write your code here
        int n =nums.size();
        if(n<k || !k) return 0;
        double re = 0,cur = 0;
        for(int i =0;i<k;i++){
            cur += nums[i];
        }
        re = cur;
        for(int i = k;i<n;i++){
            cur += nums[i] - nums[i-k];
            re = max(re,cur);
        }
        return re/k;
    }
};
