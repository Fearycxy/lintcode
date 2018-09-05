class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
       bool dp[m+1]= {0};
       dp[0] = true;
       for(int a:A)
           for(int i=m;i>=a;i--)
               if(dp[i-a]) dp[i] = true;
       for(int i=m;i>=0;i--) if(dp[i]) return i;
       return 0;
    }
};
