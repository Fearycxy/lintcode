class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int l = 0,r = heights.size()-1,re = 0;
        while(l<r){
            int m = min(heights[l],heights[r]);
            if(heights[l] == m){
                l++;
                while(heights[l]<m){
                    re += m - heights[l++];
                }
            }else{
                r--;
                while(heights[r]<m){
                    re += m- heights[r--];
                }
            }
        }
        return re;
    }
};
