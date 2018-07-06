class Solution {
public:
    /**
     * @param n: a non-negative integer
     * @return: number of numbers with unique digits
     */
    int countNumbersWithUniqueDigits(int n) {
        // Write your code here 
        if(n==0) return 0;
        int an = 10, init = 9, sub = 9;
        while(n>1 && sub >0){
            init *= sub;
            an += init;
            n--;sub--;
        }
        return an;
    }
};
