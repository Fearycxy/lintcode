class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here
        int dp[128]={0};
        for(char c:str) dp[c]++;
        for(int i=0;i<128;i++) {
            if(dp[i]==1){
                return i;
            }
        }
    }
};
