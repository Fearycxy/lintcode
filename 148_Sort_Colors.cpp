class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        // write your code here
        int mp[3] = {0};
        for(int i:nums){
            mp[i]++;
        }
        int x =0;
        for(int &i:nums){
            if(mp[x]){
                mp[x]--;
                i = x;
            }else{
                while(!mp[++x]);
                i = x;
                mp[x]--;
            }
        }
    }
};
