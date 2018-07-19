class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        vector<int> an;
        for(auto it :arrays) {
            an.insert(an.end(),it.begin(),it.end());
            inplace_merge(an.begin(),an.begin()+an.size()-it.size(),an.end());
        }
        return an;
    }
};
