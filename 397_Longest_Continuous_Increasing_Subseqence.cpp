class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        int last = INT_MIN;
        int c1 = 0,d1 = 0,re = 0;
        for(int a:A){
            if(a>last){ 
               c1++;
               d1 = 1;
               re = max(c1,re);
            }else{
                c1 = 1;
                d1++;
                re = max(d1,re);
            }
            last = a;
        }
        return re;
    }
};
