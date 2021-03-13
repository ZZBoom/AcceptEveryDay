class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> order;
        int index = 0;
        
        struct asd{
            std::string name;
            int index;
            int num;
        };
        auto cmp = [](asd a, asd b) {
            if (a.num == b.num) {
                return a.name < b.name;
            }
            return a.num > b.num;
        };

        std::vector<asd> items;
        for (const auto &item : words) {
            if (order.find(item) == order.end()) {
                order[item] = index++;
                items.push_back({item, order[item], 1});
            } else {
                items[order[item]].num++;
            }
        }
       
        std::priority_queue<asd, std::vector<asd>, decltype(cmp)> que(cmp);
        for (const auto &item : items) {
            if (que.size() < k) {
                que.push(item);
            } else {
                if (que.top().num < item.num || (que.top().num == item.num && que.top().name > item.name)) {
                    que.pop();
                    que.push(item);
                }
            }
        }
        std::vector<string> res;
        while(!que.empty()) {
            res.push_back(que.top().name);
            que.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
}; 
