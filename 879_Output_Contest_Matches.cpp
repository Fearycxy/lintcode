class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        // write your code here
        vector<string> v;
        for(int i=1;i<=n;i++) v.push_back(to_string(i));
        while(n>1){
            for(int i=0;i<n>>1;i++) {
                v[i] = "(" + v[i] + "," + v[n-i-1] + ")";
            }
            n >>= 1;
        }
        return v[0];
    }
};
