class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
long long permutationIndex(vector<int> &A) {
    // write your code here
    int n = A.size();
    long long re = 1;
    long long s = 1;
    for (int i = n - 2; i >= 0; i--) {
        int j = i;
        for (; j < n - 1;) {
            if (A[j + 1] > A[j]) {
                break;
            } else {
                swap(A[j], A[j+1]);
                j++;
            }
        }
        int it = j - i;
        re += it * s;
        s *= (n - i);
    }
    return re;
}
    
};
