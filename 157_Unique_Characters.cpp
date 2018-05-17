class Solution {
public:
    /*
     * @param str: A string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
         int a[128] = {0};
        for(char c:str){
            if(a[c]) return false;
            else a[c] =1;
        }
        return true;
    }
};
