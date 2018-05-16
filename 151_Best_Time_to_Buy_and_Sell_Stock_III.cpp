class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int local[3] = {0};  
        int global[3] = {0};
        int n = prices.size()-1;  
        for(int i=0;i<n;i++){  
            int diff = prices[i+1]-prices[i];  
            for(int j=2;j>=1;j--){  
                local[j] = max(global[j-1]+(diff>0?diff:0), local[j]+diff);  
                global[j] = max(local[j],global[j]);  
            }  
        }  
        return global[2];  
    }
};
//https://blog.csdn.net/linhuanmars/article/details/23236995
