class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
    // write your code here
    int mz = 1;
    int n = nums.size();
    if (n == 1)return nums[0];
    int mf = 1;
    int re = nums[0];
    if (re > 0) mz = max(re, 1);
    else mf = min(re, 1);
    bool flag1 = re == 1;
    int f = re;
    for (int i = 1; i < n; i++) {
        f = max(f, nums[i]);
        int z = mz;
        if (nums[i] > 0) {
            if (nums[i] * mz == 1) flag1 = true;
            mz = max(nums[i] * mz, 1);
            mf = min(mf * nums[i], 1);
        } else {
            if (mf * nums[i] == 1) flag1 = true;
            mz = max(mf * nums[i], 1);
            mf = min(nums[i] * z, 1);
        }
        re = max(re, mz);
    }
    if (re == 1) {
        if (flag1) {
            return 1;
        } else {
            return f;
        }
    } else {
        return re;
    }
}
};
