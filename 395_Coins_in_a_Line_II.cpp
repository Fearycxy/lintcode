class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */

bool firstWillWin(vector<int> &values) {
    // write your code here
    int n = values.size();
    int dp[n][2];
    for (int i = 0; i < n; i++) {
        memset(dp[i], 0, 2 * sizeof(int));
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = i < n - 1 ? -values[i + 1] : 0;
        int a = i < n - 2 ? max(dp[i + 2][0], dp[i + 2][1]) : 0;
        int b = 0;
        if (i < n - 2) {
            b = (i < n - 3) ?
                max(dp[i + 3][0], dp[i + 3][1]) : 0 - values[i + 2];
        }
        dp[i][0] = values[i] + t + min(a, b);
        int k = i < n - 1 ? values[i + 1] : 0;
        t = i < n - 2 ? -values[i + 2] : 0;
        a = i < n - 3 ? max(dp[i + 3][0], dp[i + 3][1]) : 0;
        b = 0;
        if (i < n - 3) {
            b = (i < n - 4) ?
                max(dp[i + 4][0], dp[i + 4][1]) : 0 - values[i + 3];
        }
        dp[i][1] = values[i] + k + t + min(a, b);
    }
    return max(dp[0][0], dp[0][1]) > 0;
}
};

//九章的更简洁
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        vector<int> sum, f;
        int n = values.size(), total = 0;
        if (n<3) return true;
        for (int i=0; i<n; ++i) total += values[i];   
        for (int i=0; i<n; ++i) {
            sum.push_back(total);
            total -= values[i];
        }
        f.push_back(sum[n-1]);
        f.push_back(sum[n-2]);
        for (int i=n-3; i>=0; --i)
            f.push_back(max(values[i]+(sum[i+1]-f[n-1-i-1]), values[i]+values[i+1]+(sum[i+2]-f[n-1-i-2])));
        if (f[n-1]<sum[0]-f[n-1]) return false;
        else return true;
    }
};
