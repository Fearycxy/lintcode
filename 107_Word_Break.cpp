class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here
        int n = s.size();
        if(n==0){
            return true;
        }
        int l = getMaxLength(dict);
        vector<int> vec;
        for(int i = n-1;i>=0;i--){
            if(dict.count(s.substr(i))){
                vec.push_back(i);
                if(i == 0){
                    return true;
                }
            }else{
                for(int j=vec.size()-1;j>=0;j--){
                    if(vec[j]-i>l){
                        break;
                    }
                    if(dict.count(s.substr(i,vec[j]-i))){
                        vec.push_back(i);
                        if(i == 0){
                            return true;
                        }
                        break;
                    }
                }
            }
        }
        return false;
    }
    
    int getMaxLength(unordered_set<string> &dict) {
        int maxLength = 0; // 试试看中文 
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) { 
            maxLength = maxLength > (*it).length() ? maxLength : (*it).length();
        }
        return maxLength;
    }
};
