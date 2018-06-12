class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> res;
        if(n)
            help(res,n-1,n,"(");
        return res;
    }
    
    void help(vector<string> &res,int l,int r,string s){
        if(r==0){
            res.push_back(s);
            return;
        }
        if(r>l){
            help(res,l,r-1,s+')');
        }
        if(l)help(res,l-1,r,s+'(');
    }
    
};
