class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        map<int,int> mp;
        int maxs = 0;
        int re = 0;
        for(int i = 0;i<n;i++){
            int y = nums[i];
            if(mp.count(y)){
                mp[y]++;
            }else{
                mp[y] = 1;
            }
            if(mp[y]>maxs){
                maxs = mp[y];
                re = y;
            }
        }
        return re;
    }
};
