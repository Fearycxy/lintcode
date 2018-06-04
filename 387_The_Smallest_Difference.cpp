class Solution {
public:
    /**
     * @param A: An integer array
     * @param B: An integer array
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int i = 0,j=0,an = abs(A[0]-B[0]);
        while(i<A.size()&&j<B.size()){
            an = min(an,abs(A[i]-B[j]));
            if(A[i]>B[j]){
                j++;
            }else if(A[i]<B[j]){
                i++;
            }else{
                return 0;
            }
        }
        return an;
    }
};
