    
class Solution {
public:
    /**
     * @param nums: List[int]
     * @return: return List[str]
     */
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<string> res(nums.size());
        
        vector< vector<int> > rank;
        for(int i = 0; i < nums.size(); i++){
            rank.push_back({nums[i],i});
        }
        sort(rank.begin(), rank.end(), greater<vector<int>>());
        
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) res[rank[i][1]] = "Gold Medal";
            else if(i == 1) res[rank[i][1]] = "Silver Medal";
            else if(i == 2) res[rank[i][1]] = "Bronze Medal";
            else res[rank[i][1]] = to_string(i+1);
        }
        
        return res;
    }
};
