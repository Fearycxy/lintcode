class Solution {
public:
    /**
     * @param friends: people's friends
     * @param user: the user's id
     * @return: the person who most likely to know
     */
    int recommendFriends(vector<vector<int>> &friends, int user) {
        // Write your code here
        int n = friends.size();
        int dp[n] = {0};
        int re = -1;
        int cur = 0;
        dp[user] = -1;
        for(int y:friends[user]) dp[y] = -1;
        for(int y:friends[user]){
            for(int t:friends[y]){
                if(dp[t] <0) continue;
                dp[t]++;
                if(dp[t]> cur || (dp[t]==cur && t<re)){
                    cur = dp[t];
                    re = t;
                }
            }
        }
        return re;
    }
};
