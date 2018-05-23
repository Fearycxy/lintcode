class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: An integer
     */
//想法很简单，但真的好绕。反正就是遍历到i时，i之前的能保证要么存的是正确的，要么是不合法的数据
    int firstMissingPositive(vector<int> &A) {
        // write your code here
       int s = 0,n = A.size();
       for(int i=0;i<n;i++){
           while(A[i]!=i+1 && A[i]<n&&A[i]>0&&A[i]!=A[A[i]-1] ){
               swap(A[i],A[A[i]-1]);
           }
       }
       for(int i =0;i<n;i++){
           if(A[i]!=i+1) return i+1;
       }
       return n+1;
    }
};
