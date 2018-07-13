class Solution {
public:
    /**
     * @param licensePlate: a string
     * @param words: List[str]
     * @return: return a string
     */
    string shortestCompletingWord(string &licensePlate, vector<string> &words) {
        // write your code here
        unordered_map<char,int>mp;
        for(char c:licensePlate) {
            if(c >='A' && c <= 'Z')mp[c+'a'-'A']++;
            else if(c<='z' && c >='a') mp[c] ++;
        }
        unordered_map<char,int> f;
        string re="";
        for(string &s:words){
            f.clear();
            for(char c:s)f[c]++;
            bool isvalid = true;
            for(auto p:mp){
                if(f[p.first]<p.second) {
                    isvalid = false;
                    break;
                }
            }
            if(isvalid && (re.empty() || re.size()>s.size())) re =  s;
        }
        return re;
    }
};
