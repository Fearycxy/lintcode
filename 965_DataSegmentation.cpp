class Solution {
public:
    /**
     * @param str: The input string
     * @return: The answer
     */
    vector<string> dataSegmentation(string &str) {
        // Write your code here
        vector<string> re;
        int i=0,j=0;
        while(j<=str.size()){
            if((str[j]>='a' && str[j] <='z')||(str[j]>='A' && str[j] <='Z')){
                j++;
            }else{
                if(j>i) re.push_back(str.substr(i,j-i));
                if(j < str.size() && str[j] != ' ')
                    re.push_back(string(1,str[j]));
                i = ++j;
            }
        }
        return re;
    }
};
