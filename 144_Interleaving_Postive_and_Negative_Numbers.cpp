class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        // write your code here
        int a = 0;
        for(int y:A){
            y>0 ?a++:a--;
        }
        if(a ==0) a = 1;
        unsigned long n = A.size();
        unsigned long s = 0;
        unsigned long t = 0;
        for (unsigned long i = 0; i < n; i++) {
            if ((a > 0 && (i % 2) == 1) || (a < 0 && (i % 2 ) == 0)) {
                if (A[i] < 0) continue;
                s = max(s, i);
                while (s <n-1 && A[++s] > 0);
                swap(A[i], A[s]);
                t = min(t, s);
            } else {
                if (A[i] > 0) continue;
                t = max(t, i);
                while (t <n-1 && A[++t] < 0);
                swap(A[i], A[t]);
                s = min(t, s);
            }
        }
    }
};
