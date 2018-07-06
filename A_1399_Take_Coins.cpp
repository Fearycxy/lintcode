class Solution {
public:
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    int takeCoins(vector<int> &list, int k) {
        // Write your code here
        int n  = list.size();
        int re = 0;
        for(int y = n-k;y<n;y++)re+=list[y];
        int tem = re;
        for(int i = n-k;i<n;i++){
            tem -= list[i];
            tem += list[(i+k)%n];
            if(tem>re) re = tem;
        }
        return re;
    }
};
