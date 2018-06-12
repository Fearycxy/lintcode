class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int K, vector<int> &prices) {
        // write your code here
        int ans = 0;
        if (K >= prices.size() / 2)
        {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
        int local[K+1]={0};
        int global[K+1]={0};
        int last = INT_MAX;
        for(int s:prices){
            int diff = s-last;
            for(int p=K;p>0;p--){
                local[p] = max(local[p] + diff,global[p-1] + max(diff,0));
                global[p] = max(global[p],local[p]);
            }
            last = s;
        }
        ans = global[K];
        }
        return ans;
    }
};
