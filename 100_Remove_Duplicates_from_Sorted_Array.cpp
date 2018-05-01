class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int tem = INT_MAX;
        for(auto it = nums.begin();it!=nums.end();){
            if(*it == tem){
                it = nums.erase(it);
            }else{
                tem = *it;
                it++;
            }
        }
        return nums.size();
    }
};
