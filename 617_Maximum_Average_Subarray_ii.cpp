class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, sum = 0, preSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 0; i < n; ++i) {
                sum += nums[i] - mid;
                if (i >= k) {
                    preSum += nums[i - k] - mid;
                    minSum = min(minSum, preSum);
                }
                if (i >= k - 1 && sum > minSum) {
                    check = true;
                    break;
                }
            }
            if (check) left = mid;
            else right = mid;
        }
        return right;
    }
};
