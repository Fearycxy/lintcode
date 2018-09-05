struct point {
    int x, y, dis;

    point(int x, int y, int dis) : x(x), y(y), dis(dis) {
    }
};

class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    int shortestDistance(vector<vector<int>> grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size(), house = 0;
        int xs[4] = {0, 1, -1, 0};
        int ys[4] = {1, 0, 0, -1};
        vector<vector<int>> vb(m, vector<int>(n, 0));
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<point> que;
                    vector<vector<bool>> visit(m, vector<bool>(n, false));
                    que.emplace(i, j, 0);
                    house++;
                    while (!que.empty()) {
                        auto p = que.front();
                        que.pop();
                        if (!grid[p.x][p.y])vec[p.x][p.y] += p.dis;
                        for (int f = 0; f < 4; f++) {
                            int x = p.x + xs[f];
                            int y = p.y + ys[f];
                            if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y] && !grid[x][y]) {
                                vb[x][y]++;
                                visit[x][y] = true;//切记 这里要直接将访问置为true ！！
                                que.emplace(x, y, p.dis + 1);
                            }
                        }
                    }
                }
            }
        }
        int re = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] && vb[i][j] == house) {
                    re = min(re, vec[i][j]);
                }
            }
        }
        return re;
    }
};
