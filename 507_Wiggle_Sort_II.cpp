class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int len = nums.size(), low = 0, high = len - 1, mid = nums[len / 2], i = 0;
        auto index = [&](int pos) -> int & { return nums[(1 + pos * 2) % (len | 1)]; };
        while (i <= high) {
            if (index(i) > mid) swap(index(i++), index(low++));
            else if (index(i) < mid) swap(index(i), index(high--));
            else i++;
        }
    }
 //小于中位数的放到偶数位，大于的放到奇数位，相等的奇数往后推，偶数的往前推，本身的由于相隔一无所谓，奇偶若重叠则不可的到合理结果
};
