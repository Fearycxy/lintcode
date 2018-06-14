class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: the nth digit of the infinite integer sequence
     */
    int findNthDigit(int n) {
        // write your code here
        long long len = 1,start = 1,cnt = 9;
        while(n>len * cnt){
            n -= len*cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }
        start += (n-1)/len;
        string s = to_string(start);
        return s[(n-1)%len]-'0';
    }
};
