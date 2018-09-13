class Solution {
public:
    /**
     * @param n: an integer
     * @param k: an integer
     * @return: how many problem can you accept
     */
    long long canAccept(long long n, int k) {
        // Write your code here
        n/=k;
        return (sqrt(0.25+2*n)-0.5);
    }
};
