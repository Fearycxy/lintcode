class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
        // write your code here
        if(p.empty()  && s.empty()) return true;
        if(p.empty()) return false;
        if(s.empty()){
            if(p.size() == 1 || p[1] != '*') return false;
            return isMatch(s,p.substr(2));
        }
        if(s[0]==p[0] || p[0]=='.'){
            if(p.size() >1 && p[1] == '*') return isMatch(s.substr(1),p) || isMatch(s,p.substr(2));
            else return isMatch(s.substr(1),p.substr(1));
        }
        if(p.size()>1 && p[1] == '*')return isMatch(s,p.substr(2));
        return false;  
    }
};
