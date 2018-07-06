class Solution {
public:
    /**
     * @param matrix : the martix
     * @return: the distance of grid to the police
     */
    vector<vector<int>> policeDistance(vector<vector<int>> &matrix ) {
        // Write your code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> an(m,vector<int>(n,0));
        queue<pair<int,int>> que;
        for(int i=0;i<m;i++)
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 1)
                    que.emplace(i,j);
                if(matrix[i][j] == -1)
                    an[i][j] = -1;
            }
        pair<int,int> step[4] = {{0,1},{0,-1},{-1,0},{1,0}};    
        while(!que.empty()){
            auto f = que.front();que.pop();
            int l = an[f.first][f.second];
            for(auto a:step){
                auto g = f;
                g.first += a.first;
                g.second += a.second;
                if(g.first<0 || g.first>=m || g.second < 0 || g.second >= n) continue;
                if(matrix[g.first][g.second] == 0 && an[g.first][g.second] == 0){
                    an[g.first][g.second] = l+1;
                    que.emplace(g.first,g.second);
                }
            }
        }
        return an;
    }
};
