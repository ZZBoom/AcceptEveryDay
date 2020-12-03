class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int vis[107][107];
        int n = maze.size();
        int m = maze[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = INT_MAX;
            }
        }
        auto check = [=](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m) {
                return false;
            }
            return true;
        };
        struct Node{
            int x;
            int y;
            int step;
            Node(int xx, int yy, int sstep) : x(xx), y(yy), step(sstep) {}
            bool operator < (Node b) const {
                return (this->step > b.step);
            }
        };
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        std::priority_queue<Node> que;
        auto sstart = Node(start[0], start[1], 0);
        que.push(sstart);
        vis[start[0]][start[1]] = 0;
        while(false == que.empty()) {
            auto now = que.top();
            que.pop();
            if (now.x == destination[0] && now.y == destination[1]) {
                return now.step;
            }
            for (int i = 0; i < 4; i++) {
                int x = now.x;
                int y = now.y;
                int step = 0;
                while(check(x + dx[i], y + dy[i])) {
                    if (maze[x + dx[i]][y + dy[i]] == 1) {
                        break;
                    }
                    x += dx[i];
                    y += dy[i];
                    step++;    
                }
                assert(maze[x][y] == 0);
                step += now.step;
                if (step < vis[x][y]) {
                    vis[x][y] = step;
                    auto end = Node(x, y, step);
                    que.push(end);
                }
            }
        }
        return -1;
    }
};
