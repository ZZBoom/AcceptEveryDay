#include <vector>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); ++i) {
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (std::abs(target - sum) < std::abs(target - res)) {
          res = sum;
        }
        if (target == sum) {
          return target;
        } else if (sum < target)
          left++;
        else
          right--;
      }
    }
    return res;
  }
};

int main() { 
  std::vector<int> a{-1,2,1,-4}; 
  printf("%d", Solution().threeSumClosest(a, 2));

}

