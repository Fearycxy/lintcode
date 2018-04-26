class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int maxs = 1;
        if(n == 0){
            return 0;
        }
        int tem[n];
        fill(tem,tem+n,1);
        vector<int>::iterator it;
        for(it = nums.begin();it!=nums.end();it++){
            auto f = it;
            while(f != nums.begin()){
                f--;
                 if(*f < *it){
                int g = tem[it-nums.begin()] =max(tem[it-nums.begin()], tem[f-nums.begin()]+1);
                if(g>maxs){
                    maxs = g;
                }
            }
            }
             if(*f < *it){
                int g = tem[it-nums.begin()] =max(tem[it-nums.begin()], tem[f-nums.begin()]+1);
                if(g>maxs){
                    maxs = g;
                }
            }
           
        }
        return maxs;
    }
};
