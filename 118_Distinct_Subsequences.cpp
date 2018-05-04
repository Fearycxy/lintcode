class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        // write your code here
        int m = S.size();
        int n = T.size();
        int dp[m][n];
        dp[0][0] =S[0]==T[0]? 1:0;
        for(int j =1;j<m;j++){
            dp[j][0] =S[j] == T[0] ? dp[j-1][0]+1:dp[j-1][0];
        }
        for(int i = 1;i<n;i++){
            dp[0][i] = 0;
        }
        for(int i = 1;i<m;i++){
            for(int j =1;j<n;j++){
                if(S[i]==T[j]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


//我的优化
class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        // write your code here
        int m = S.length();
        int n = T.length();
        if(m==0 || n==0){
            return 0;
        }
        int dp[m][2];
        dp[0][0] =S[0]==T[0]? 1:0;
        for(int j =1;j<m;j++){
            dp[j][0] =S[j] == T[0] ? dp[j-1][0]+1:dp[j-1][0];
        }
        for(int j = 1;j<n;j++){
            dp[0][j%2]=0;
            for(int i =1;i<m;i++){
                if(S[i]==T[j]){
                    dp[i][j%2] = dp[i-1][(j-1)%2]+dp[i-1][j%2];
                }else{
                    dp[i][j%2] = dp[i-1][j%2];
                }
            }
        }
        return dp[m-1][(n-1)%2];
    }
};

//🐟大神的优化，都一样，都是滚动数组，不过它这个牛逼的地方在于加了一个空取空为1，这个辅助的数省去了一个多余的判断
class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        // write your code here
        int m = S.size();
        int n = T.size();
        int dp[n+1]={0};
        dp[0] = 1;
        for(auto it = S.begin();it!=S.end();it++){
            for(int j = n-1;j>=0;j--){
                if((*it) == T[j]){
                    dp[j+1]+=dp[j];
                }
            }
        }
        return dp[n];
        
    }
};
