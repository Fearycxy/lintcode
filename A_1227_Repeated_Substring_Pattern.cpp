class Solution {
public:
    /**
     * @param s: a string
     * @return: return a boolean
     */
    bool repeatedSubstringPattern(string &s) {
        // write your code here
        int i =1,n=s.size();
        int l = 2;
        while(l < sqrt(n)+1){
            if(n %l ==0 && (inspect(l,s) || inspect(n/l,s)))  return true;
            l++;
        }
        return false;
    }
    
    inline bool inspect(int l,const string &s){
        string base = s.substr(0,l);
        int t = l;
        while(t < s.size()){
            if(base != s.substr(t,l)) return false;
            t += l;
        }
        return true;
    }
};
