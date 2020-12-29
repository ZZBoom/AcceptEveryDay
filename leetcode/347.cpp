class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [](pair<int, int>& m, pair<int, int>& n) {
            return m.second > n.second;
        };
        std::unordered_map<int, int> cnts;
        for (auto &v : nums) {
            cnts[v]++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);
        for (auto& [num, count] : cnts) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        std::vector<int> ans;
        ans.reserve(k);
       while(false == q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
}; 
