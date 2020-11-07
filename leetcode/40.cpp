#include <assert.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void dfs(std::vector<std::vector<int>> &ans, std::vector<int> &temp,
           int target, int sum, std::vector<int> &candidates, int j) {
    if (sum == target) {
      ans.push_back(temp);
      return;
    }
    for (int i = j; i < candidates.size(); i++) {
      if (i > j && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (sum + candidates[i] > target) {
        continue;
      }
      temp.push_back(candidates[i]);
      dfs(ans, temp, target, sum + candidates[i], candidates, i + 1);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    for (int i = 0; i < candidates.size(); i++) {
      if (i > 0 && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (candidates[i] > target) {
        continue;
      }
      temp.push_back(candidates[i]);
      dfs(ans, temp, target, candidates[i], candidates, i + 1);
      temp.pop_back();
    }
    return ans;
  }
};

int main() {}
