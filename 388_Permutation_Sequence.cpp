class Solution {
public:
    /**
     * @param n: n
     * @param k: the k th permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        // write your code here
        std::vector<int> dp(n+1,1);
        std::vector<char> nums(n+1,'0');
        for(int i =1;i<=n;i++) dp[i] = i * dp[i-1];
        for(int i = 1;i<=n;i++)nums[i] += i;
        string an;
        k--;//!!!!!!!!!
        for(int i =n;i>0;i--){
            int j = k/dp[i-1];
            an.push_back(nums[j+1]);
            k %= dp[i-1];
            nums.erase(nums.begin()+j+1);
        }
        return an;
    }
};
