class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        // write your code here
        if(matrix.empty()) return 0;
        int m = matrix.size(), n= matrix[0].size(), result = 0;
        vector<int> cache(n+1,0);
        for(int i=1;i<=m;i++){
            int last = 0;
            for(int j = 1;j<=n;j++){
                if(matrix[i-1][j-1] != 0){
                    int tem = cache[j];
                    cache[j] = min(min(cache[j-1],last),cache[j]) +1;
                    last = tem;
                    result = max(cache[j],result);
                }else {
                    last = cache[j];
                    cache[j] = 0;
                }
            }
        }
        return result * result;
    }
};
