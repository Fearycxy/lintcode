class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        // write your code here
        char a[128]={0};
        for(char c:s) a[c]++;
        for(char c:t) a[c]--;
        for(int t:a) if(t) return false;
        return true;
    }
};
