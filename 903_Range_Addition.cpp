class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        vector<int> re(length+1,0);
        for(auto y:updates){
            re[y[0]] += y[2];
            re[y[1]+1] -= y[2];
        }
        for(int i=1;i<length;i++) re[i]+= re[i-1];
        re.pop_back();
        return re;
    }
};
