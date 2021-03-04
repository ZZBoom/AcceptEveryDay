/*
        int mid=Left+(Right-Left+1)/2;  
        if(Judge(mid))  
            Left=mid;  
        else  
            Right=mid-1; 
*/
class Solution {
public:
    bool judge(int i, const std::vector<int> &a) {
        if (i > 0 && a[i] == a[i-1] && ((i + 1) & 1) == 0) {
            return true;
        }
        if ((i + 1) < a.size() && a[i] == a[i+1] && ((i + 2) & 1) == 0) {
            return true;
        }
        return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (judge(mid, nums)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (judge(l, nums)) {
            return nums[l + 1];
        }
        return nums[0];
    }
};
