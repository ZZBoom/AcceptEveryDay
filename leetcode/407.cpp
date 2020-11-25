class Solution {
public:
  typedef pair<int, pair<int, int>> PIII;
  int trapRainWater(vector<vector<int>> &heightMap) {
    if (heightMap.empty()) {
      return 0;
    }
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    int R = heightMap.size();
    int C = heightMap[0].size();
    vector<vector<int>> visited(R, vector<int>(C, 0));
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
          heap.push(make_pair(heightMap[r][c], make_pair(r, c)));
          visited[r][c] = 1;
        }
      }
    }
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int ans = 0;
    while (!heap.empty()) {
      PIII iter = heap.top();
      heap.pop();
      for (int i = 0; i < 4; i++) {
        int r = iter.second.first + dx[i];
        int c = iter.second.second + dy[i];
        if (r >= 0 && r < R && c >= 0 && c < C && !visited[r][c]) {
          if (heightMap[r][c] < iter.first) {
            ans += iter.first - heightMap[r][c];
            heap.push(make_pair(iter.first, make_pair(r, c)));
          } else {
            heap.push(make_pair(heightMap[r][c], make_pair(r, c)));
          }
          visited[r][c] = 1;
        }
      }
    }
    return ans;
  }
};
