class Solution {
public:
    /**
     * @param prices: a list of integers
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int n = prices.size();
        int global[4] = {0};
        int local[2] = {0};
        for(int i=1;i<n;i++){
            local[i%2] = max((i>=3 ? global[(i+1)%4] :0),local[(i+1)%2]) + prices[i]- prices[i-1];
            global[i%4] = max(global[(i+3)%4],local[i%2]);
        }
        return global[(n+3)%4];
    }
};
