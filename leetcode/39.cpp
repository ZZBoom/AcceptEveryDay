#include <vector>
using namespace std;

class Solution {
public:
  void dfs(std::vector<std::vector<int>> &ans, std::vector<int> &conbine,
           int index, std::vector<int> &candidates, int target) {
    if (target == 0) {
      ans.push_back(conbine);
      return;
    }
    if (index == candidates.size()) {
      return;
    }
    dfs(ans, conbine, index + 1, candidates, target);
    if (target - candidates[index] >= 0) {
      conbine.push_back(candidates[index]);
      dfs(ans, conbine, index, candidates, target - candidates[index]);
      conbine.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::vector<int> conbine;
    std::vector<std::vector<int>> ans;
    dfs(ans, conbine, 0, candidates, target);
    return ans;
  }
};

int main() {

}
