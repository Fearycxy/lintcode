class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums
     */
    int findMin(vector<int> &nums) {
        // write your code here
        long long sum = 0ll;
        for(int j:nums) sum = j+ sum;
        unordered_map<long long,bool>mp;
        vector<long long> vec;
        mp[0] = true;
        for(int i:nums){
            for(auto y:mp){
                vec.push_back(y.first+i);
            }
            for(auto y:vec){
                mp[y] = true;
            }
            vec.clear();
        }
        for(int k = (sum>>1);k>=0;k--){
            if(mp[k]) return sum-k*2;
        }
    }
};
