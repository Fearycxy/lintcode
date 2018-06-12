class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
         vector<string> an;
        for(int i =0;i<s.length();i++){
            if(i && s[i] == '+' && s[i-1] == '+'){
                string t = s;
                t[i] = '-';
                t[i-1] = '-';
                an.push_back(t);
            }
        }
        return an;
    }
};
