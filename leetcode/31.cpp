#include <vector>
using namespace std;

class Solution {
public:
  // 1 3 4 5 1 2
  // 0 1 2 3 4 5
  // 1 3 4 5 2 1
  // 1 3 5 1 2 4
  // 1 3 5 4 2
  // 1 4 2 3 5
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int pos = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (i - 1 >= 0) {
        if (nums[i] > nums[i - 1]) {
          pos = i;
          break;
        }
      }
    }
    if (pos == -1) {
      pos = 0;
    }
    std::sort(nums.begin() + pos, nums.end());
    if (pos > 0) {
      for (int i = pos; i < n; i++) {
        if (nums[i] > nums[pos - 1]) {
          std::swap(nums[i], nums[pos - 1]);
          break;
        }
      }
    }
  }
};

int main() {}
