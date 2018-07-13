class Solution {
public:
    /**
     * @param s: a string
     * @param d: List[str]
     * @return: return a string
     */
    string findLongestWord(string &s, vector<string> &d) {
        // write your code  here
        string an = "";
        for(string &t:d){
            if(t.size() <an.size())continue;
            int i = 0;
            for(char c:s)
                if(i<t.size() && c == t[i]) i++;
            if(i == t.size() && (t.size() > an.size() || t < an)) an = t;
        }
        return an;
    }
};
