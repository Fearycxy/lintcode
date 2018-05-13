class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
     //http://bangbingsyb.blogspot.com/2014/11/leetcode-palindrome-partitioning//-i-ii.html
     typedef vector<string> VS;
    vector<vector<string>> partition(string &s) {
        // write your code here
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i =n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if((i+1>=j-1 || dp[i+1][j-1]) &&s[i]==s[j]){
                    dp[i][j] = true;
                }
            }
        }
        vector<VS> re;VS sol;
        help(re,sol,0,s,dp);
        return re;
        
    }
private:
    void help(vector<VS> &re,VS &sol, int start, string &s,vector<vector<bool>> &dp){
        if(start == s.size()){
            re.push_back(sol);
            return;
        }
        for(int i = start;i<s.size();i++){
            if(dp[start][i]){
                sol.push_back(s.substr(start,i-start+1));
                help(re,sol,i+1,s,dp);
                sol.pop_back();
            }
        }
    }
};
