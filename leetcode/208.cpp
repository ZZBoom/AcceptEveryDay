class Trie {
public:
    struct Node {
        std::vector<int> next;
        int index;
        bool is_end;
    };
    /** Initialize your data structure here. */
    Trie() {
        Node item = {.next = {}, .index = 0, .is_end = true};
        tree_.push_back(item);
        num_ = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int key = 0;
        for (size_t i = 0; i < word.size(); i++) {
            int new_key = -1;
            int index = word[i] - 'a';
            bool find = false;
            for (auto item : tree_[key].next) {
                if (index == tree_[item].index) {
                    new_key = item;
                    find = true;
                    break;
                }
            }
            if (false == find) {
                Node item = {.next = {}, .index = index, .is_end = false};
                tree_.push_back(item);
                num_++;
                new_key = num_;
            }
            tree_[key].next.push_back(new_key);
            key = new_key;
        }
        tree_[key].is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int key = 0;
        for (size_t i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            bool find = false;
            for (auto item : tree_[key].next) {
                if (index == tree_[item].index) {
                    key = item;
                    find = true;
                    break;
                }
            }
            if (false == find) {
                return false;
            }
        }
        return (tree_[key].is_end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int key = 0;
        for (size_t i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            bool find = false;
            for (auto item : tree_[key].next) {
                if (index == tree_[item].index) {
                    key = item;
                    find = true;
                    break;
                }
            }
            if (false == find) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<Node> tree_;
    int num_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
