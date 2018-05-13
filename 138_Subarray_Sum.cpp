class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        unordered_map<int,int> mp;
        int i =0,sum=0;
        mp[0] = -1;
        vector<int> re;
        for(int p:nums){
            sum+=p;
            if(mp.count(sum)){
                re.push_back(mp[sum]+1);
                re.push_back(i);
                break;
            }
            mp[sum] = i++;
        }
        return re;
    }
};
