class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
   int singleNumberII(vector<int> &A) {
    // write your code here
    int a[32] = {0};
    for (auto it = A.begin(); it != A.end(); it++) {
        for (int i = 0; i < 32; i++) {
            a[i] += ((*it) >> i) & 1;
        }
    }
    int re = 0;
    for (int i = 31; i >= 0; i--) {
        re <<= 1;
        if (a[i] % 3 != 0) {
            re += 1;
        }

    }
    return re;
}
};
