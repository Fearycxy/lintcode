class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        if(n < 5){
            return 0;
        }
        // write your code here, try to do it without arithmetic operators.
      return n / 5 + trailingZeros(n/5);
    }
};
