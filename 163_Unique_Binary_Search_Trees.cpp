class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */

//卡特兰数
    int numTrees(int n) {
        // write your code here
        int a[n+1];
        memset(a,0,sizeof(a));
        a[0] =1;
        for(int i = 1;i<n+1;i++){
            for(int j =0;j<i;j++){
                a[i] += a[j]*a[i-j-1];
            }
        }
        return a[n];
    }
};
