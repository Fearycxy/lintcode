class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        map<char ,int>mp;
        for(char c:s){
            if(mp[c]) mp.erase(mp.find(c));
            else mp[c] = true;
        }
        return mp.size()<2;
    }
};
