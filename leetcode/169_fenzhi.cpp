/*
这样以来，我们就可以使用分治法解决这个问题：将数组分成左右两部分，分别求出左半部分的众数 a1 以及右半部分的众数 a2，随后在 a1 和 a2 中选出正确的众数。
算法
我们使用经典的分治算法递归求解，直到所有的子问题都是长度为 1 的数组。长度为 1 的子数组中唯一的数显然是众数，直接返回即可。
如果回溯后某区间的长度大于 1，我们必须将左右子区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。
否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。
  */
class Solution {
public:
    bool isMajorityElement(const vector<int>& nums, int l, int r, int value) {
        int count = 0;
        for (int i = l; i <= r; i++) {
            if (nums[i] == value) {
                count++;
            }
        }
        return count > ((r - l + 1) >> 1);
    }
    int getMajorityElement(const vector<int>& nums, int l, int r) {
        if (l == r) {
            //printf("%d %d %d\n", l, r, nums[l]);
            return nums[l];
        }
        int mid = (l + r) >> 1;
        int lValue = getMajorityElement(nums, l, mid);
        int rValue = getMajorityElement(nums, mid + 1, r);
        if (lValue == rValue) {
            //printf("%d %d %d\n", l, r, lValue);
            return lValue;
        }
        if (isMajorityElement(nums, l, r, lValue)) {
            //printf("%d %d %d\n", l, r, lValue);
            return lValue;
        }
        if (isMajorityElement(nums, l, r, rValue)) {
            //printf("%d %d %d\n", l, r, rValue);
            return rValue;
        }
        //printf("%d %d %d\n", l, r, -1);
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        return getMajorityElement(nums, 0, nums.size() - 1);
    }
};
// 0 6
// 0 3
// 4 6

// 0 1
// 2 3

// 4 5
// 6 6
