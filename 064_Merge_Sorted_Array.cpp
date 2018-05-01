class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int s[m];
        for(int i = 0;i<m;i++){
            s[i] =A[i];
        }
        int k,t = 0;
        int i = 0;
        while(k<m || t<n ){
            while((s[k]<=B[t] || t ==n )&& k<m){
                A[i] = s[k];
                i++;
                k++;
            }
            while((s[k]>=B[t] || k==m)&& t<n){
                A[i] = B[t];
                i++;
                t++;
            }
        }
    }
};
