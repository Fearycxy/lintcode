class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        stack<char> st;
        unordered_map<char,char> mp= {{'}','{'},{')','('},{']','['}};
        for(char c:s){
            if(c == '{' || c == '(' || c == '['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(st.top() == mp[c]){
                    st.pop();
                }else return false;
            }
        }
        return st.empty();
    }
};
