class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        // Write your code here
        if(!n) return false;
        return !(1162261467 % n) ;
    }
};
