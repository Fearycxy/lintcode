class Solution {
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        // write your code here
        if(words1.size() != words2.size()) return false;
        unordered_map<string,unordered_map<string,bool>>mp;
        for(auto &y :pairs){
            mp[y[0]][y[1]] = true;
            mp[y[1]][y[0]] = true;
        }
        for(int i =0;i<words1.size();i++){
            if(words1[i] != words2[i] && !mp[words1[i]][words2[i]]) return false;
        }
        return true;
    }
};
