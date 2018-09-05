class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        // Write your code here
        int find = -1,i = 0,j=0,n=S.size(), m = T.size(),len = INT_MAX;
        while(i<n){
            if(S[i]==T[j] && ++j == m){
                int end = i;
                while(S[i--] != T[j-1] || --j);
                if(end-(i++)<len){
                    len = end-i+1;
                    find = i;
                }
            }
            i++;
        }
        return find == -1 ? "" : S.substr(find,len);
    }
};
