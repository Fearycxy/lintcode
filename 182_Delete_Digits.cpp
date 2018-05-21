class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int k) {
        // write your code here
        int n = A.length();
        int m = n-k;
        int last =0;
        string re = "";
        for(int i = 0;i<m;i++){
            int t= 10;
            for(int j = max(last,i);j<n-m+i+1;j++){
                int p = A[j]-'0';
                if(p<t){
                    t = p;
                    last = j+1;
                }
            }
            if(re.empty() && t == 0) continue;
            re += to_string(t);
        }
        return re;
    }
};
