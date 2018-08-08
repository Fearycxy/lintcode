class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        // Write your code here
        int i = 0, j = -1,n= array.size();
        vector<int> next(n + 1, -1);
        while (i < n) {
            if (j == -1 || array[i] == array[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return i - next[i];
    }
};
