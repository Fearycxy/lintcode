class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        // Write your code here
        int n = flights.size(), k = days[0].size(), res = 0;
        int dp[n][2]={0};
        for (int j = k - 1; j >= 0; --j) {//这个处理特别巧妙，全题最关键的点
            for (int i = 0; i < n; ++i) {
                dp[i][j%2] = days[i][j];
                for (int p = 0; p < n; ++p) {
                    if ((i == p || flights[i][p]) && j < k - 1) {
                        dp[i][j%2] = max(dp[i][j%2], dp[p][(j+1)%2] + days[i][j]);
                    }
                    if (j == 0 && (i == 0 || flights[0][i])) res = max(res, dp[i][0]);
                }
            }
        }
        return res;
    }
    
};
