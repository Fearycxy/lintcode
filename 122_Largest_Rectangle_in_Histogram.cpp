http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
so amazing
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
       stack<int> s;
       int re = 0;
       height.push_back(0);
       for(int i =0;i<height.size();i++){
           if(s.empty() || height[s.top()] < height[i]) s.push(i);
           else{
               int tmp = s.top();s.pop();
               re = max(re,height[tmp] *(s.empty()?i:i-s.top()-1));
               i--;
           }
       }
       return re;
    }
};
