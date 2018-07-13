class Solution {
public:
    /**
     * @param nums: 
     * @return: the maximum result of ai XOR aj, where 0 â‰¤ i, j < n
     */
    int findMaximumXOR(vector<int> &nums) {
        // Write your code here
        int res =0,mask = 0;
        unordered_set<int> st;
        for(int i =31;i>=0;i--){
            mask |= 1<<i;
            st.clear();
            for(int p:nums) st.insert(mask & p);
            int t = res | (1<< i);// assume the ith bit is 1 and determined
            for(int pre:st){
                if(st.find(pre ^ t) != st.end()){
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};
