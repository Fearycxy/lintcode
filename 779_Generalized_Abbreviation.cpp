class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        // Write your code here
        vector<string> res;
        dfs(word,0,res,word);
        return res;
    }

    void dfs(string &word,int start,vector<string> &res,string &now){
        if(start>=now.size()){
            res.push_back(now);
            return;
        }
        dfs(word,start+1,res,now);
        for(int i=start+1;i<=now.size();i++){
            string num = to_string(i-start);
            string next =now.substr(0,start)+ num +now.substr(i,now.size()-i);
            dfs(word,start+num.size()+1,res,next);
        }
    }
};
