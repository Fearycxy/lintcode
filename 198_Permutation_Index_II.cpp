class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
long long permutationIndexII(vector<int> &A) {
    // write your code here
    int n = A.size();
    long long re = 1;
    long long s = 1;
    for(int i = n - 2; i >= 0; i--) {
        int j = i, x = 0, last = INT_MIN;
        int count = 1;
        int tmp = 0;
        for (; j < n - 1;) {
            if (A[j + 1] >= A[j]) {
                while (j < n - 1 && A[j + 1] == A[j++]) {
                    count++;
                }
                break;
            } else {
                swap(A[j], A[j + 1]);
                if (A[j] != last) {
                    tmp +=  x;
                    last = A[j];
                    x = 1;
                } else x++;
                j++;
            }
        }
        tmp +=  x;
        re += tmp * s/ count;
        s = s * (n - i) / count;
    }
    return re;
}
};
