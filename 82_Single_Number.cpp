class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int re = 0;
        int a[32];
        for(auto it = A.begin();it!=A.end();it++){
            re ^= *it;
        }
        return re;
    }
};
