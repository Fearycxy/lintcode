class Solution {
public:
    /**
     * @param N: an integer
     * @return: return an integer
     */
    int maxA(int N) {
        // write your code here
         int res = N;
        for (int i = 1; i < N - 2; ++i) {
            res = max(res, maxA(i) * (N - 1 - i));
        }
        return res;
    }
};
