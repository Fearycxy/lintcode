class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here
        string ans;
        string tem;
        string digit;
        int num;
        int brackets=0;
        for(char c:s){
            if(brackets==0){
                if(c>='0'&&c<='9'){
                   digit.push_back(c);
                }else if(c == '['){
                    if(digit.empty()){
                        num = 0;
                    }else{
                        num = stoi(digit);
                        digit.clear();
                        brackets++;
                    }
                }else{
                    ans.push_back(c);
                }
            }else{
                if(c == '['){
                    brackets++;
                }else if(c == ']'){
                    brackets--;
                }
                if(brackets==0){
                    for(int i=0;i<num;i++){
                        ans += expressionExpand(tem);
                    }
                    num = 0;
                    tem.clear();
                }else{
                    tem.push_back(c);
                }
                
            }
        }
        return ans;
    }
};
