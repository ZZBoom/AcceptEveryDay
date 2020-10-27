#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.size() < 3)
      return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0)
        break;
      if (i != 0 && nums[i] == nums[i - 1])
        continue;
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (0 == sum) {
          vector<int> temp;
          temp.push_back(nums[i]);
          temp.push_back(nums[left++]);
          temp.push_back(nums[right--]);
          res.push_back(temp);
          while (left < right && nums[left] == nums[left - 1])
            ++left;
          while (left < right && nums[right] == nums[right + 1])
            --right;
        } else if (sum < 0)
          left++;
        else
          right--;
      }
    }
    return res;
  }
};
int main() {
  std::vector<int> a{-1, 0, 1, 2, -1, -4};
  std::vector<int> b{0, 0, 0, 0};
  auto ans = Solution().threeSum(b);
  for (auto ii : ans) {
    for (auto i : ii) {
      printf("%d ", i);
    }
    printf("\n");
  }
}
