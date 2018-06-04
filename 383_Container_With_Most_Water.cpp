class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int start = 0, end = heights.size()-1;
        int re = 0;
        while(start < end){
            re = max(re,(end-start) * min(heights[start],heights[end]));
            if(heights[start] < heights[end]) start++;
            else end --;
        }
        return re;
    }
};
