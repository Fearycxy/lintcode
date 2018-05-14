class Solution {
public:
    /**
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return n && n!= INT_MIN && !(n-1 & n);
    }
};
