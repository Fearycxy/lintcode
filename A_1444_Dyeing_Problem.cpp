class Solution {
public:
    /**
     * @param n: the number of sectors
     * @param m: the number of colors
     * @return: The total number of plans.
     */
    int getCount(int n, int m) {
        // Write your code here
        const int MOD = 1e9 + 7;
        if(n==1) return m;
        if(n==2) return m*(m-1);
        if(m<3) {
            if(n&1 == 1) return 0;
            if(n& 1 == 0&& m== 2) return 2;
        }
        long long g = m ;
        long long a = m, b = 0;
        for(int i =1;i<n;i++){
            long long f = b;
            b= a *(g-1) + b *(g-2);
            b%= MOD;
             a = f ;
        }
        return b;
    }
};
