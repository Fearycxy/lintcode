class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string s, string p) {
        // write your code here
        int m =s.size();int n =p.size();
        vector<vector<int>> dp (m+1,vector<int>(n+1,-1));
        int i =0,j=0;
        return help(s,p,dp);
    }
    
    bool help(string &s, string &p,std::vector<vector<int>> &dp,int i=0,int j=0){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i == s.size()){
            for(int r = j;r<p.size();r++){
                if(p[r] != '*') {
                   return dp[i][j] = 0;
                }
            }
            return dp[i][j] = 1;
        }
        if(j== p.size()) return dp[i][j] = 0;
        if(p[j]=='?' || p[j] == s[i]){
            return dp[i][j] = help(s,p,dp,i+1,j+1);
        }else if(p[j]=='*'){
            return  dp[i][j] =  help(s,p,dp,i+1,j) || help(s,p,dp,i,j+1);
        }else{
            return dp[i][j] = 0;
        }
    }
};
