class Solution {
public:
    bool isPossible(vector<int>& nums) {
        struct Node{
            int num;
            int v;
           // Node (int snum, int sv) : num(snum), v(sv) {}
            bool operator < (const Node &a) const {
                if (this->v == a.v) {
                    return this->num > a.num;
                }
                return this->v < a.v;
            }
        };
        int n = nums.size();
        std::priority_queue<Node> vis;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            std::vector<Node> temp;
            while(nums[i] == v) {
                if (false == vis.empty()) {
                    auto item = vis.top();
                    if (item.v + 1 == nums[i]) {
                        Node tmp = {.num = item.num + 1, .v = item.v + 1};
                        temp.push_back(tmp);
                        vis.pop();
                    } else {
                        Node tmp = {.num = 1, .v = v};
                        temp.push_back(tmp);
                    }
                } else {
                    Node tmp = {.num = 1, .v = v};
                    temp.push_back(tmp);
                }
                if (i + 1 >= n || nums[i + 1] != v) {
                    break;
                }
                i++;
            }
            for (auto item : temp) {
                vis.push(item);
            }
        }
        while(false == vis.empty()) {
            auto item = vis.top();
            vis.pop();
            if (item.num < 3) {
                return false;
            }
        }
        return true;
    }
};
