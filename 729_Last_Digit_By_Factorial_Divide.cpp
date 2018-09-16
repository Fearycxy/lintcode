class Solution {
public:
    /**
     * @param A: the given number
     * @param B: another number
     * @return: the last digit of B! / A! 
     */
    int computeLastDigit(long long A, long long B) {
        // write your code here
        if(B-A>=10 || ((A/10)%10) != (B/10)%10) return 0;
        else {
            int a =A%10, b = B%10 ,re = 1;
            while(b>a) re*=b--;
            return re%10;
        }
    }
;
