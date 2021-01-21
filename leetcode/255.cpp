class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        std::stack<int> st;
        int new_min = INT_MIN; 
        for (auto item : preorder) {
            if (new_min > item) {
                return false;
            }
            while(!st.empty() && st.top() < item) {
                new_min = st.top();
                st.pop();
            }
            st.push(item);
        }
        return true;
    }
};
// 1 3 2
