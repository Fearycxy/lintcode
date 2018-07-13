class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a boolean
     */
    bool isPossible(vector<int> &nums) {
        // write your code here
        unordered_map<int,int> fre,need;
        for(int i:nums) fre[i]++;
        for(int i:nums){
            if(fre[i] == 0) continue;
            if(need[i]>0){
                need[i]--;
                need[i+1]++;
            }else if(fre[i+1] && fre[i+2]){
                fre[i+1]--;
                fre[i+2]--;
                need[i+3]++;
            }else return false;
            fre[i]--;
        }
        return true;
    }
};
