class Solution {
public:
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  void dfs(Robot &robot, unordered_set<string> &visited, int x, int y,
           int dir) {
    robot.clean();
    for (int i = 1; i <= 4; i++) {
      robot.turnRight();
      int new_dir = (dir + i) % 4;
      int xx = x + dx[new_dir];
      int yy = y + dy[new_dir];
      string next = to_string(xx) + ',' + to_string(yy);
      if (visited.find(next) != visited.end())
        continue;
      visited.insert(next);
      if (robot.move()) {
        dfs(robot, visited, xx, yy, new_dir);

        robot.turnRight();
        robot.turnRight();

        robot.move();

        robot.turnRight();
        robot.turnRight();
      }
    }
  }
  void cleanRoom(Robot &robot) {
    unordered_set<string> visited;
    visited.insert("0,0");
    dfs(robot, visited, 0, 0, 0);
  }
};
