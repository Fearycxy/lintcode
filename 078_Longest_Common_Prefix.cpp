class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        int i = 0;
        if(strs.size() == 0){
            return "";
        }
        string an;
        int l = strs[0].size();
        while(true){
            if(i == l){
                break;
            }
            char t = strs[0][i];
            for(vector<string>::iterator it = strs.begin();it!=strs.end();it++){
                if((*it).size()==i || (*it)[i] != t ){
                    return an;
                }
               
            }
            an+=t;
            i++;
        }
        return an;
    }
};
