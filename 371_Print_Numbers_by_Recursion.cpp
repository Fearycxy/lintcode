class Solution {
public:
    /**
     * @param n: An integer
     * @return: An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> re;
        help(re,pow(10,n)-1);
        return re;
    }
private:
    void help(vector<int> &an,int cur){
        if(!cur) return;
        help(an,cur-1);
        an.push_back(cur);
    }
};
