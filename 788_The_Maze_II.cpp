class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        if (maze.empty() || maze[0].empty()) return -1;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs{{0,  -1},
                                 {-1, 0},
                                 {0,  1},
                                 {1,  0}};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int re = 0;
        q.emplace(start[0], start[1]);
        visited[start[0]][start[1]] = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == destination[0] && t.second == destination[1]) {
                if(re == 0 || re > visited[t.first][t.second]) re = visited[t.first][t.second]; 
            }
            for (auto dir : dirs) {
                int x = t.first, y = t.second;
                int last = visited[t.first][t.second] - 1;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    last++;
                }
                x -= dir[0];
                y -= dir[1];
                if (!visited[x][y] || visited[x][y] > last) {
                    visited[x][y] = last;
                    q.push({x, y});
                }
            }
        }
        return re-1;
    }
};
