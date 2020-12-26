class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > que;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        for (auto &item : intervals) {
            if (que.empty()) {
                que.push(item[1]);
            } else {
                auto top = que.top();
                if (top <= item[0]) {
                    que.pop();
                }
                que.push(item[1]);
            }
        }
        return que.size();
    }
};
