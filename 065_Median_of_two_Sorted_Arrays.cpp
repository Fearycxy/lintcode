class Solution {
public:
    
  
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
         int m = A.size();
        int n = B.size();
         bool isOU = (m+n)%2 == 0;
        if(m == 0){
            return isOU? (B[n/2-1]+B[n/2]) /2.0: B[n/2];
        }
        if(n == 0){
            return isOU? (A[m/2-1]+A[m/2]) /2.0: A[m/2];
        }
        int re[2];
        int k,t = 0;
       
        int i = 0;
        while(k<m || t<n ){
            while((A[k]<=B[t] || t ==n )&& k<m){
                re[0] = re[1];
                re[1] = (A[k]);
                k++;
                if(i++ == (m+n)/2){
                    return isOU ? (re[1]+re[0])/2.0 : re[1];
                }
            }
            while(n && (A[k]>=B[t] || k==m)&& t<n){
                re[0] = re[1];
                re[1] = (B[t]);
                t++;
                if(i++ == (m+n)/2){
                    return isOU ? (re[1]+re[0])/2.0 : re[1];
                }
            }
        }
        return 0;
    }
};
