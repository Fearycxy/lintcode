class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here
        int g=0,f= 0,n = nums.size(),s=0,t=0;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i<n-1){
                int f1 = g+nums[i];
                g = max(g,f);
                f = f1;
            }
            if(i){
                int f2 = s+nums[i];
                s = max(s,t);
                t = f2;
            }
        }
        return max(max(g,f),max(s,t));
        
    }
};
