#include <assert.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    struct HInfo {
      int h;
      int _h;
      int index;
    };
    std::stack<HInfo> sta;
    int ans = 0;
    int index = 0;
    for (auto h : height) {
      HInfo now = {.h = h, ._h = h, .index = ++index};
      while (false == sta.empty() && sta.top().h <= now.h) {
        auto top_item = sta.top();
        sta.pop();
        ans += (top_item.h - top_item._h) * (now.index - top_item.index - 1);
        if (false == sta.empty()) {
          sta.top()._h = top_item.h;
        }
      }
      if (false == sta.empty()) {
          auto top_item = sta.top();
          ans += (now.h - top_item._h) * (now.index - top_item.index - 1);
      }
      sta.push(now);
    }
    return ans;
  }
};

