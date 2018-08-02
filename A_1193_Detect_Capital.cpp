class Solution {
public:
    /**
     * @param word: a string
     * @return: return a boolean
     */
    bool detectCapitalUse(string &word) {
        // write your code here
        if(word.empty())return false;
        auto fun = [](char &c){
            return c>='A' && c <='Z';
        };
        for(int i =2;i<word.size();i++){
            if(fun(word[i]) != fun(word[i-1])) return false; 
        }
        return true;
    }
};
