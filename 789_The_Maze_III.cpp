class Solution {
public:
    /**
     * @param maze: the maze
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole) {
        // write your code here
        if (maze.empty() || maze[0].empty()) return "impossible";
        if (ball[0] == hole[0] && ball[1] == hole[1]) return "";
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs{{0,  -1},
                                 {-1, 0},
                                 {0,  1},
                                 {1,  0}};
        string step = "lurd";
        vector<vector<pair<int, string>>> visited(m, vector<pair<int, string>>(n, make_pair(0, "")));
        queue<pair<int, int>> q;
        pair<int, string> re = {INT_MAX, "impossible"};
        q.emplace(ball[0], ball[1]);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                auto dir = dirs[i];
                char c = step[i];
                int x = t.first, y = t.second;
                auto last = visited[t.first][t.second];
                last.second.push_back(c);
                bool isInHole = false;
                while (true) {
                    if (x == hole[0] && y == hole[1]) {
                        if (re.first > last.first || (re.first == last.first && re.second > last.second)) {
                            re = last;
                            isInHole = true;
                            break;
                        }
                    }
                    x += dir[0];
                    y += dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == 1) break;
                    last.first++;
                }
                x -= dir[0];
                y -= dir[1];
                if (isInHole) continue;
                if (last.first == visited[t.first][t.second].first) continue;
                auto v = visited[x][y];
                if (!v.first || v.first > last.first || (v.first == last.first && v.second > last.second)) {
                    visited[x][y] = last;
                    q.push({x, y});
                }
            }
        }
        return re.second;
    }
};
