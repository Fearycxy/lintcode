class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the minimum number of replacements
     */
    int integerReplacement(int n) {
        // Write your code here
        if(n == INT_MAX) return 32;
        int cnt = 0;
        while(n >1){
            if((n & 1) == 0){
                n = n>> 1;
            }else{
                if(n == 3) return cnt+2;
                if((n & 3) == 3 ){
                    n++;
                }else{
                    n--;
                }
            }
            cnt++;
        }
        return cnt;
    }
};
