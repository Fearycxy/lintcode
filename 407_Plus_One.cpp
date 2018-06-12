class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        // write your code here
        vector<int> an;int y = 1;
        for(auto it= digits.rbegin();it !=digits.rend();it++){
            int r = *it + y;
            if(r>9) {
                y = 1;
                r %=10;
            }else y = 0;
            an.insert(an.begin(),r);
        }
        if(y)an.insert(an.begin(),1);
        return an;
    }
};
