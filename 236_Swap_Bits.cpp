class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    int swapOddEvenBits(int x) {
        // write your code here
        unsigned a = x;
        unsigned odd = a & 0x55555555;
        unsigned even = a & 0xaaaaaaaa;
        odd <<= 1;
        even >>= 1;
        return odd +even;
    }
};
