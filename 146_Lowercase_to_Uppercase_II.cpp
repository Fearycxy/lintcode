class Solution {
public:
    /**
     * @param str: A string
     * @return: A string
     */
    string lowercaseToUppercase2(string &str) {
        // write your code here
        int s = 'A'-'a';
        for(char &c:str)
            if(c>='a' && c <= 'z') 
                c+=s;
        return str;
    }
};
