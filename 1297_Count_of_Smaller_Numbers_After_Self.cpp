class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> countSmaller(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<int> re(n),list;
        for(int i = n-1;i>=0;i--){
            int left = 0, right = list.size();
            while(left < right){
                int mid = left + ((right-left)>>1);
                if(list[mid] < nums[i]) {
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
            re[i] = right;
            list.insert(list.begin()+right,nums[i]);
        }
        return re;
        
    }
};
