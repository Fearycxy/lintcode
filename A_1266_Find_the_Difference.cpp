class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: the letter that was added in t
     */
    char findTheDifference(string &s, string &t) {
        // Write your code here
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};
