class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        // write your code here
        const int m = heights.size();
        if (!m) return 0;
        const int n = heights[0].size();
        if (!n) return 0;
        int re = 0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>que;
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    visit[i][j] = true;
                    que.emplace(heights[i][j],i*n+j);
                }
            }
        }
        int mx = INT_MIN;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!que.empty()){
            auto cur = que.top();que.pop();
            mx = max(mx,cur.first);
            int s = cur.second/n;
            int t = cur.second %n;
            for(auto mv:dir){
                int x = s+mv.first;
                int y = t+mv.second;
                if(x<0||x>=m-1||y<0||y>=n-1||visit[x][y]) continue;
                visit[x][y] = true;//important
                if(heights[x][y]<mx) {
                    re += mx - heights[x][y];
                }
                 que.emplace(heights[x][y],x*n+y);
            }
        }
        return re;
    }

};
