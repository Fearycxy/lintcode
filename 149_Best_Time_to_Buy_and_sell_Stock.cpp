class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int m = INT_MAX;
        int re = 0;
        for(int f:prices){
            re = max(f-m,re);
            m = min(m,f);
        }
        return re;
    }
};
