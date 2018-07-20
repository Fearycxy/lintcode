class Solution {
public:
    /**
     * @param n: the number of integers
     * @param k: the number of distinct integers
     * @return: any of answers meet the requirment
     */
    vector<int> constructArray(int n, int k) {
        // Write your code here
        vector<int> an;
        int i = 1,j=n;
        while(i<=j) an.push_back(k>1?(k--%2?i++:j--):i++);
        return an;
    }
};
