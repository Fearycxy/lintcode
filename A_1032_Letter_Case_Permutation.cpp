class Solution {
public:
    /**
     * @param S: a string
     * @return: return a list of strings
     */
    vector<string> letterCasePermutation(string &S) {
        // write your code here
        vector<string> re;
        if(S.empty()) return {""};
        string next = S.substr(1);
        auto a = letterCasePermutation(next);
        vector<int> step = {0};
        if((S[0]>='a' && S[0] <='z')){
            step.push_back('A'-'a');
        }else if((S[0]>='A' && S[0] <='Z')){
            step.push_back('a'-'A');
        }
        for(auto &y:a){
            for(int l:step){
                re.push_back(string(1,S[0]+l) + y);
            }
        }
        return re;
    }
};
