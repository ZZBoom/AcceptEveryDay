class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        int index = 0;
        if (index == m) {
            return true;
        }
        std::stack<int> sta;
        for (auto item : pushed) {
            sta.push(item);
            while (!sta.empty() && sta.top() == popped[index]) {
                index++;
                sta.pop();
            }            
        }
        return sta.empty();
    }
};
