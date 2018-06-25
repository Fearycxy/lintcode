class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> an;
        string s;
        unordered_map<char,string> mp ={
          {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
          {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        dfs(an,s,digits,mp);
        return an;
    }
    
    void dfs(vector<string> &an, string s,string digits,unordered_map<char,string> &mp){
        if(digits.empty()){
            if(!s.empty())an.push_back(s);
            return;
        }
        string vec = mp[digits[0]];
        digits = digits.substr(1);
        for(char c:vec){
            dfs(an,s+c,digits,mp);
        }
    }
};
