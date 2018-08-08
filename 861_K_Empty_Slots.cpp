class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        // Write your code here
        int res = INT_MAX, left = 0, right = k + 1, n = flowers.size();
        vector<int> days(n, 0);
        for (int i = 0; i < n; ++i) days[flowers[i] - 1] = i + 1;
        for (int i = 1; right < n; ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) res = min(res, max(days[left], days[right]));
                 left++;
                right++;
                i = left;
            }
        }
       return (res == INT_MAX) ? -1 : res;
    }
};
