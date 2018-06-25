class Solution{
public:
    typedef pair<int,int> pt;
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pt &a, const pt &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (auto &a:envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), a.second);
            if (it == dp.end()) dp.push_back(a.second);
            else *it = a.second;
        }
        return dp.size();
    }
};

