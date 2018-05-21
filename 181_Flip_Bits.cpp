class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count = 0;  
        for (unsigned int c = a ^ b; c != 0; c = c >> 1) {//unsigned 太关键了
            count += c & 1;
        }
        return count;
    }
};
