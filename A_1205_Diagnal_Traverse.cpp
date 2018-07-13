class Solution {
public:
    /**
     * @param matrix: a 2D array
     * @return: return a list of integers
     */
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> an;
        if(matrix.empty()) return an;
        int x = 0,y = 0;
        int m = matrix.size(),n = matrix[0].size();
        bool up = true;
        an.push_back(matrix[0][0]);
        while(x != m-1 || y != n-1){
            if(up){
                if(x==0 || y==n-1){
                    if(y<n-1)y++;
                    else x++;
                    up = false;
                }else{
                    x--;
                    y++;
                }
            }else{
                if(y==0 || x == m-1){
                    if(x<m-1)x++;
                    else y++;
                    up = true;
                }else{
                    x++;
                    y--;
                }
            }
             an.push_back(matrix[x][y]);
        }
        return an;
    }
};
