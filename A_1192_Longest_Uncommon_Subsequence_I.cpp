class Solution {
public:
    /**
     * @param a: a string
     * @param b: a string
     * @return: return a integer
     */
    int findLUSlength(string &a, string &b) {
        // write your code here
         return a == b ? -1 : max(a.size(), b.size());
    }
};
