class Solution {
public:
    /**
     * @param words: a string array
     * @return: the maximum product
     */
    int maxProduct(vector<string> &words) {
        // Write your code here
        int n =words.size();
        int mask[n] = {0};
        int an = 0;
        for(int i=0;i<n;i++){
            for(char c:words[i]) mask[i] |= 1 << (c-'a');
            for(int j =0;j<i;j++){
                if(!(mask[i] & mask[j])){
                   an = max(an,int(words[i].size() * words[j].size())); 
                }
            }
        }
        return an;
    }
};
