class Solution {
public:
    /**
     * @param n: a non-negative integer
     * @return: the total number of full staircase rows that can be formed
     */
    int arrangeCoins(int n) {
        // Write your code here
        double m = n;
        return (sqrt(2*m+0.25)-0.5);
    }
};
