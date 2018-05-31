class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        int ml = 0;
        int start = 0;
        int n = s.size();
        int vec[n][n] = {0};//这里用vector会超时，神奇
        for(int i =0;i<n;i++){
            for(int j =0;j<=i;j++){
                if(s[i]==s[j] && (i-j<3 ||vec[j+1][i-1])){
                    vec[j][i] = true;
                    if(i-j+1>ml){
                        ml = i-j+1;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start,ml);
    }
};
