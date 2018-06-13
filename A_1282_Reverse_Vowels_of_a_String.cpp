class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    string reverseVowels(string &s) {
        // write your code here
        unordered_map<char,int> mp={
            {'a',1},{'A',1},
            {'e',1},{'E',1},
            {'i',1},{'I',1},
            {'o',1},{'O',1},
            {'u',1},{'U',1}
        };
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            while(mp[s[l]]==0 && l<r) l++;
            while(mp[s[r]]==0 && l<r) r--;
            if(l<r) swap(s[l++],s[r--]);
        }
        return s;
    }
};
