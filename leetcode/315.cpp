class Solution {
public:
    // 离散化 + 树状数组
    typedef int LL;
    std::vector<int> c;
    int Maxn;
    inline int lowbit(int x){return x & -x;}
    LL Sum(int x){
        LL ans = 0;
        while(x){
            ans = ans + c[x];
            x = x - lowbit(x);
        }
        return ans;
    }
    void add(int x){
        while(x < Maxn){
            ++c[x];
            x = x + lowbit(x);
        }
    }
    int get(int &sum, std::unordered_map<int, int> &mp, const int index) {
        if (mp.count(index) == 0) {
            mp[index] = ++sum;
        }
        return mp[index];
    }
    vector<int> countSmaller(vector<int>& nums) {
        auto a = nums;
        std::sort(a.begin(), a.end());
        int sum = 0;
        std::unordered_map<int, int> mp;
        for (auto item : a) {
            get(sum, mp, item);
        }
        int n = nums.size();
        std::vector<int> ans (n);
        c.resize(sum + 1, 0);
        Maxn = sum + 1;
        for (int i = n - 1; i >= 0; i--) {
            int x = get(sum, mp, nums[i]);
            ans[i] = Sum(x - 1);
            add(x);
        }
        return ans;
    }
};
