class Solution {
public:
    /**
     * @param str: the str
     * @return: the sum of bytes in the last word
     */
    int judgeTheLastNumber(string &str) {
        // Write your code here
        while(str.length() >2){
            if(str[0]=='1')str = str.substr(2);
            else str = str.substr(1);
        }
        return str[0]=='1'?2:1;
    }
};
