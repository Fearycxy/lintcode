class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        int dp[n];
        fill(dp,dp+n,1);
        for(int i =1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
        
    }
};

//下面是我脑子瓦特就是纯开心写的一个数学解法，相当于一共有M-1+n-1个选择，每次可以选择横走或竖走，相当于M+n-2取m-1个的组合数
class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        if(m>n){
            swap(m,n);
        }
        long long s = 1;
        long long l =1;
        m = m-1;
        while(m){
            s = s*(m+n-1);
            if(s%m==0){
                s=s/m;
            }else{
              l*=m;
            }
            m--;
        }
        return s/l;
        
    }
};
