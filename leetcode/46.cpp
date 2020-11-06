#include <assert.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  std::vector<int> vis;
  int index;
  std::vector<std::vector<int>> ans;
  void dfs(std::vector<int> &temp, std::vector<int> &nums) {
    if (temp.size() == nums.size()) {
      ans.push_back(temp);
      return;
    }
    for (auto i = 0; i < nums.size(); i++) {
      if (vis[i]) continue;
      vis[i] = 1;
      temp.push_back(nums[i]);
      dfs(temp, nums);
      vis[i] = 0;
      temp.pop_back();
    }
  }
  int Factorial(size_t n) {
    int ans_n = 1;
    for (auto i = 1; i <= n; ++i) {
      ans_n = ans_n * i;
    }
    return ans_n;
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vis.resize(nums.size(), 0);
    std::vector<int> temp;
    temp.reserve(nums.size());
    ans.reserve(Factorial(nums.size()));
    dfs(temp, nums);
    return ans;
  }
};

int main() {
  
}

