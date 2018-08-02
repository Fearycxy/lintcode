class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return an integer
     */
    int repeatedStringMatch(string &A, string &B) {
        // write your code here
        int n = B.size();
        string f = A;
        int i =1;
        while(f.size()<n){
            f += A;
            i++;
        }
        if(f.find(B) != string::npos) return i;
        f += A;
         if(f.find(B) != string::npos) return i+1;
         return -1;
    }
};
