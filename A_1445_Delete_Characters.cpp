class Solution {
public:
    /**
     * @param s: The string s
     * @param t: The string t
     * @return: Return if can get the string t
     */
    bool canGetString(string &s, string &t) {
        // Write your code here
        int n = s.size();
        int m = t.size();
        int l= 0,r = 0;
        while(r != m ){
            do
            if(l==n) return false;
            while(s[l++] != t[r]);
            r++;
        }
        return true;
    }
};
