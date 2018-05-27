class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        // write your code here
        int n = A.length();
        if(n != B.length()) return false;
        int a[128] = {0};
        for(int i=0;i<n;i++){
            a[A[i]]++;
            a[B[i]]--;
        }
        for(int f:a){
            if(f) return false;
        }
        return true;
    }
};
