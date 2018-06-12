class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // Write your code here
        if(matrix.empty() || matrix[0].empty()) return true;
        int m = matrix.size(),n= matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                int y = matrix[i][j];
                if(i>=j && matrix[i-j][0] !=y) return false;
                if(j>=i && matrix[0][j-i] != y) return false;
            }
        }
        return true;
    }
};
