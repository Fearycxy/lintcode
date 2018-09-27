class Solution {
public:
    /**
     * @param words: the given list of words
     * @return: the number of different transformations among all words we have
     */
    int uniqueMorseRepresentations(vector<string> &words) {
        // Write your code here
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>st;
        for(auto & w:words){
            string s;
            for(char c:w){
                s+=morse[c-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};
