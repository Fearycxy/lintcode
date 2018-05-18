class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int last = INT_MAX;
        int re = 0;
        for(int f:prices){
            if(f>last){
                re += f- last;
            } 
            last = f;
        }
        return re;
    }
};
