class Solution {
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int ml = 0;
        vector<string> re;
        for(auto it = dictionary.begin();it != dictionary.end();it++){
            if((*it).size()>=ml){
                if((*it).size()>ml) re.clear();
                re.push_back(*it);
                ml = (*it).size();
            }
        }
        return re;
    }
};
