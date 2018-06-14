class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        // Write your code here
        int n = nums.size();
        k = min(k,n);
        int i, j;
        for (i = 0; i < n; i++) {
            for(int j = i+1;j<min(i+k,n-1);j++){
                if(nums[j] == nums[i]) return "YES";
            }
        }
        return "NO";
    }
};
