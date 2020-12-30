class Solution {
public:
    std::vector<int> ori_;
    std::vector<int> nums_;
    Solution(vector<int>& nums) : ori_(nums), nums_(nums) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums_ = ori_;
        return ori_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < ori_.size(); i++) {
            int index = (rand() + ori_.size()) % ori_.size();
            if (i != index) {
                std::swap(nums_[i], nums_[index]);
            }
        }
        return nums_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
