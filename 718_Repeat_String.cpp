class Solution {
public:
    /**
     * @param A: string A to be repeated
     * @param B: string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        // write your code here
        if(A.empty()) return B.empty()?1:-1;
        int n1 = A.size(), n2 = B.size(), cnt = 1;
        string t = A;
        while (t.size() < n2) {
            t += A;
            ++cnt;
        }
        if (t.find(B) != string::npos) return cnt;
        t += A;
        return (t.find(B) != string::npos) ? cnt + 1 : -1;
    }
};
