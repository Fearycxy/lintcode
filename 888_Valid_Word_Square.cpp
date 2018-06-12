class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        int n = words.size();
        for(int i =0;i<n;i++)
            for(int j=0;j<n;j++)
                if(words[i][j]!= words[j][i]) return false;
        return true;
    }
};
