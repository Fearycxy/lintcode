class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        // write your code here
        int n = s.size(),end = 0,last = 0;
        bool bold = false;
        string re;
        for(int i = 0;i<n;i++){
            for(string &str:dict){
                int len = str.size();
                if(i+len <=end || i+len >n ) continue;
                if(s.substr(i,len) == str) end = i+ len;
            }
            if(end > i){
                if(!bold)last = i;
                bold = true;
            }else{
                if(bold){
                    re += "<b>" + s.substr(last,i-last) + "</b>";
                    bold = false;
                }
                re.push_back(s[i]);
            }
        }
        if(bold) re += "<b>" + s.substr(last,n-last) + "</b>";
        return re;
    }
    
};
