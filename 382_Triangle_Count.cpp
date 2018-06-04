class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(),S.end());
        int n = S.size(),an = 0;
        for(int i =0;i<n-2;i++){
            for(int j =i+1;j<n-1;j++){
                int y = S[i]+S[j];
                for(int t = j+1;t<n;t++){
                    if(y>S[t]) an++;
                    else break;
                }
            }
        }
        return an;
    }
};
