//滚动数组
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        long long g=0,f=0;
        for(int i:A){
            long long f1 = g + i;
            g = max(g,f);
            f =f1;
        }
        return max(g,f);
    }
};
