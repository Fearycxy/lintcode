class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here
        while(!word.empty()){
            if(abbr.empty())return false;
            if(word[0]==abbr[0]){
                word = word.substr(1);
                abbr = abbr.substr(1);
            }else if(abbr[0]>='1' && abbr[0]<='9'){
                int i =0;
                while(i<abbr.size() && abbr[i]>='0' && abbr[i]<='9') i++;
                int t= stoi(abbr.substr(0,i));
                if(t>word.size()) return false;
                word = word.substr(t);
                abbr = abbr.substr(i);
            }else{
                return false;
            }
        }
        return abbr.empty();
    }
};
