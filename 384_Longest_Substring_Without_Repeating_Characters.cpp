class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        int re = 0;
        string last = "";
        for(char c:s){
            int r= last.find(c);
            if(r == string::npos){
                re = max((int)last.size()+1,re);
            }else{
                last = last.substr(r+1);
            }
             last += c;
        }
        return re;
    }
};//也可以用个数组记录char出现的上个位置
