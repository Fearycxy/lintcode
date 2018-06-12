class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n  = values.size();
        if( n & 1 == 0)  return true;//interesting point
        vector<vector<int>> mp(n,vector<int>(n,INT_MAX));
        return help(mp,0,n-1,values) >0;
    }
    
    int help(vector<vector<int>> &mp,int i,int j,vector<int> &values){
        if(mp[i][j] != INT_MAX) return mp[i][j];
        if(i==j) return values[i];
        if(i==j-1) return max(values[i]- values[j],values[j]- values[i]);
        int i1 = values[j] + min(help(mp,i,j-2,values)- values[j-1],help(mp,i+1,j-1,values)- values[i]);
        int i2 = values[i] + min(help(mp,i+1,j-1,values) - values[j],help(mp,i+2,j,values)- values[i+1]);
        return mp[i][j] = max(i1,i2);
    }
};
