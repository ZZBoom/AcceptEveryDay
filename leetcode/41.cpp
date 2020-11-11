#include <assert.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;


// 4 2 6 3 5
// 3 2 6 4 5
// 3 2 4 6 5
// 2 3 4 6 5
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
