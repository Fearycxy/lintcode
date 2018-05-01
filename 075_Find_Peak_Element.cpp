class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        int n = A.size();
        int start = 1;
        int end = n-2;
        while(start <end){
            int k = start + ((end-start) >>1);
            if(A[k]>A[k-1]){
                if(A[k]>A[k+1]){
                    return k;
                }else{
                    start = k+1;
                }
            }else{
                end = k-1;
            }
        }
        return start;
    }
};
