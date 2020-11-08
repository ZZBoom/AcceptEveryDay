class Solution {
public:
  // 1 2 3
  // 2 4 6
  // 0 1 2 3 4 5
  //     l r
  // 0 1 2 3 4 5 6
  //       l
  //       r
  // left  (n + m - 1) / 2
  // right (n + m) / 2
  int getKthElement(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    int index1 = 0, index2 = 0;
    
    while(true) {
      if (index1 == n) {
        return nums2[index2 + k - 1];
      }

      if (index2 == m) {
        return nums1[index1 + k - 1];
      }

      if (k == 1) {
        return std::min(nums1[index1], nums2[index2]);
      }

      printf("%d\n", index1 + index2);
      int new_index1 = std::min(index1 + k / 2 - 1, n - 1);
      int new_index2 = std::min(index2 + k / 2 - 1, m - 1);
      int val1 = nums1[new_index1];
      int val2 = nums2[new_index2];
      if (val1 <= val2) {
        k -= (new_index1 - index1 + 1);
        index1 = new_index1 + 1;
      } else {
        k -= (new_index2 - index2 + 1);
        index2 = new_index2 + 1;
      }
    }
  }
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
  }
};
