#include <assert.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  std::vector<std::string> dic{"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
  void dfs(std::string &digits, int index, std::vector<std::string> &ans,
           std::string &content) {
    if (index == digits.size()) {
      ans.push_back(content);
      return;
    }
    auto str = dic[digits[index] - '2'];
    for (auto c : str) {
      content.push_back(c);
      dfs(digits, index + 1, ans, content);
      content.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    std::vector<std::string> ans;
    std::string content;
    dfs(digits, 0, ans, content);
    return ans;
  }
};

int main() {}
