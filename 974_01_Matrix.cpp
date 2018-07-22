class Solution {
public:
    /**
     * @param matrix: a 0-1 matrix
     * @return: return a matrix
     */
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        // write your code here
        std::queue<pair<int,int>> que;
        int m = matrix.size(),n = matrix.back().size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]){
                    matrix[i][j] = INT_MAX-1;
                }else{
                    que.emplace(i,j);
                }
            }
        }
        pair<int,int> step[4] = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!que.empty()){
            auto p = que.front();que.pop();
            int f  = matrix[p.first][p.second];
            for(auto s:step){
                int x = p.first+s.first,y = p.second+s.second;
                if(x>=0 && y>=0 && x<m &&y<n && matrix[x][y]>f+1){
                    matrix[x][y] = f+1;
                    que.emplace(x,y);
                }
            }
        }
        return matrix;
    }
};
