class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        if(!n || !k) return 0;
        if(n ==1 )return k;
        int a = k,b=k * (k-1);
        for(int i = 2;i<n;i++){
            int t = a;
            a = b;
            b = (t+b)*(k-1);
        }
        return a +b;
    }
};
