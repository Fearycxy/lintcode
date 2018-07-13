class Solution {
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    int findTargetSumWays(vector<int> &nums, int s) {
        // Write your code here
        int an = 0;
        dfs(an,nums,0,s,0);
        return an;
    }
    
    void dfs(int &an,vector<int> &nums,int cur,const int s,int al){
        if(cur == nums.size()){
            if(al == s) an++;
            return;
        }
        dfs(an,nums,cur+1,s,al+nums[cur]);
        dfs(an,nums,cur+1,s,al-nums[cur]);
    }
};
