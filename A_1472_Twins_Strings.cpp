class Solution {
public:
    /**
     * @param s: the first string
     * @param t: the second string
     * @return: If they are twin strings
     */
    string isTwin(string &s, string &t) {
        // Write your code here
        if(s.size()!=t.size())return "No";
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i=i+2){
            mp[s[i]]++;mp[t[i]]--;
        }
        for(auto y:mp)
            if(y.second !=0)return "No";
        for(int i=1;i<s.size();i=i+2){
            mp[s[i]]++;mp[t[i]]--;
        }
        for(auto y:mp)
            if(y.second !=0)return "No";
        return "Yes";
    }
};
