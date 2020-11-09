class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> que;
    for (auto item : nums) {
      if (que.size() < k) {
        que.push(item);
      } else {
        assert(false == que.empty());
        if (que.top() < item) {
          que.pop();
          que.push(item);
        }
      }
    }
    assert(false == que.empty());
    return que.top();
  }
};
