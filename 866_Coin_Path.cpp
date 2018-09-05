//soulution1 not good ,due to the memory that it costs is too much(Please forgive me for my stupid English)
class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    vector<int> cheapestJump(vector<int> &A, int B) {
        // write your code here
        int n = A.size();
        vector<int> dp(n, INT_MAX);
        vector<vector<int>> paths(n);
        dp[0] = A[0];
        paths[0] = {1};
        for (int i = 1; i < n; i++) {
            if (A[i] == -1) continue;
            int k = -1;
            for (int m = min(i, B); m >= 1; m--) {
                if (dp[i - m] == INT_MAX) continue;
                if (dp[i - m] + A[i] < dp[i]) {
                    k = i - m;
                    dp[i] = dp[i - m] + A[i];
                }else if(dp[i - m] + A[i] == dp[i] && k!=-1){
                    paths[i-m].push_back(i+1);
                    paths[k].push_back(i+1);
                    int tem = k;
                    if(paths[i-m]<paths[k]){
                        k = i-m;
                    }
                    paths[i-m].pop_back();
                    paths[tem].pop_back();
                }
            }
            if (k != -1) {
                paths[i].insert(paths[i].begin(), paths[k].begin(), paths[k].end());
                paths[i].push_back(i+1);
            }
        }
        return paths[n - 1];
    }
};

//solution2 parent points
class Solution {
public:
   vector<int> cheapestJump(vector<int>& A, int B) {
       if (A.back() == -1) return {};
        int n = A.size();
        vector<int> res, dp(n, INT_MAX), pos(n, -1);
        dp[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] == -1) continue;
            for (int j = i + 1; j <= min(i + B, n - 1); ++j) {//每个点都尽可能往小的点跳
                if (dp[j] == INT_MAX) continue;
                if (A[i] + dp[j] < dp[i]) {
                    dp[i] = A[i] + dp[j];
                    pos[i] = j;
                }
            }
        }
        if (dp[0] == INT_MAX) return res;
        for (int cur = 0; cur != -1; cur = pos[cur]) {
            res.push_back(cur + 1);
        }
        return res;
   }
};
