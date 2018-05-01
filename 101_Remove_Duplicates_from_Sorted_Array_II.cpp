class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int tem = INT_MAX;
        int flag = false;
        for(auto it = nums.begin();it!=nums.end();){
            if(*it == tem){
                if(flag){
                    it = nums.erase(it);
                }else{
                    it++;
                }
                flag = true;
            }else{
                flag = false;
                tem = *it;
                it++;
            }
        }
        return nums.size();
    }
};
