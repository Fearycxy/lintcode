class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        int dp[128]={0};
        for(char c:s) dp[c]++;
        int t =0, f = 0;
        for(int i:dp){
            if(i &1 == 1){
                f =1 ;
                t+=(i-1);
            }
            else t+=i;
        }
        return t+f;
    }
};
