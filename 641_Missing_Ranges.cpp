class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector<string> an;
        typedef long long ll;
        ll next = lower , up = upper;
        function<void (ll)> fuc = [&](ll i){
            if(i>next) {
                if(i >1+next) an.push_back(to_string(next) + "->" + to_string(i-1));
                else an.push_back(to_string(next));
            }
            next = i+1;
        };
        for(ll i:nums)fuc(i);
        fuc(up+1);
        return an;
    }
};
