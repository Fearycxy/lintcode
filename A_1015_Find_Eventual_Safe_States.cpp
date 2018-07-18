class Solution {
public:
    /**
     * @param graph: a 2D integers array
     * @return: return a list of integers
     */
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        // write your code here
        int n = graph.size()+1;
        vector<int> re;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
            if(dfs(i,dp,graph)) re.push_back(i);
        return re;
    }
    
    bool dfs(int i,vector<int> &dp,vector<vector<int>> &graph){
        if(dp[i]) return dp[i] == 2;
        dp[i] = 1;
        for(int y:graph[i])
            if(!dfs(y,dp,graph))
                return false;
        dp[i] = 2;
        return true;
    }
};
