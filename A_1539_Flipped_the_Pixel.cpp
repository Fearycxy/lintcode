class Solution {
public:
    /**
     * @param Byte: 
     * @return: return the answer after flipped
     */
    vector<vector<int>> flippedByte(vector<vector<int>> &Byte) {
        // Write your code here
        vector<vector<int>> res;
        int i, j, n = INT_MAX;
        for(auto &row: Byte)
            n = min(n, (int)row.size());
        for(auto &row: Byte){
            for(i = 0; i < row.size(); i += n){
                res.push_back({});
                for(j = i + n - 1; j >= i; j--){
                    res.back().push_back(!row[j]);
                }
            }
        }//题目描述根本不是人话 直接复制粘贴了 从答案看明白这题是啥意思
        return res;
    }
};
