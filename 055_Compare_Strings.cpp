class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        // write your code here
        if(B.size()==0){
            return true;
        }else if(A.size() == 0){
            return false;
        }
        map<char,int> mpa;
        map<char,int> mpb;
        for(char d = 'A';d<'Z';d++){
            mpa[d] = 0;
            mpb[d] = 0;
        }
        for(char c:A){
            if(mpa.count(c)){
                mpa[c] ++;
            }
        }
    
        for(char c:B){
            if(mpb.count(c)){
                mpb[c]++;
            }
        }
        for(char d = 'A';d<'Z';d++){
            if(mpa[d]<mpb[d]){
                return false;
            }
        }
        return true;
    }
};
