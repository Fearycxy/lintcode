class Solution {
public:
    /**
     * @param arr: The given matrix
     * @return: Return the mininum sum
     */
    long long minimumSubmatrix(vector<vector<int>> &arr) {
        // Write your code here
        if(arr.empty()) return 0;
        int nx = arr.size(), ny = arr[0].size();
        long long ans;
        long long sum[nx+1][ny] = {0};
        long long s, t;
        for(int i = 0; i < nx; i++)
            for(int j = 0; j < ny; j++)
                sum[i+1][j] = sum[i][j] + arr[i][j];
        ans = INT_MAX;
        for(int i = 0; i < nx; i++)
            for(int j = i; j < nx; j++){
                s = 0;
                for(int k = 0; k < ny; k++){
                    s = min(s,0ll) + sum[j+1][k] - sum[i][k];
                    ans = min(ans, s);
                }
            }
        return ans;
    }
       
};
