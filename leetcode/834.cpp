#include <vector>
using namespace std;

class Solution {
public:
  void dfs_count(int u, int fa, const std::vector<std::vector<int>> &edges,
                 std::vector<int> &counts, std::vector<int> &dp) {
    counts[u] = 1;
    for (auto v : edges[u]) {
      if (v == fa) {
        continue;
      }
      dfs_count(v, u, edges, counts, dp);
      counts[u] += counts[v];
      dp[u] += dp[v] + counts[v];
    }
  }
  void dfs_weight(int u, int fa, const std::vector<std::vector<int>> &edges,
                  std::vector<int> &dp, vector<int> &counts) {
    for (auto v : edges[u]) {
      if (v == fa) {
        continue;
      }
      dp[v] += dp[u] - dp[v] - counts[v] + counts.size() - counts[v];
      dfs_weight(v, u, edges, dp, counts);
    }
  }
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
    vector<vector<int>> graph(N);

    for (int i = 0; i < N - 1; i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }

    std::vector<int> counts(N);
    std::vector<int> dp(N);
    dfs_count(0, -1, graph, counts, dp);
    dfs_weight(0, -1, graph, dp, counts);
    return dp;
  }
};

int main() {}
