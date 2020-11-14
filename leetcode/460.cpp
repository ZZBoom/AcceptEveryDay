

class LFUCache {
private:
  struct Node {
    int val;
    int key;
    int freq;
  };
  int min_freq_;
  int capacity_;
  std::unordered_map<int, std::list<Node>::iterator> key_table_;
  std::unordered_map<int, std::list<Node>> freq_table_;

public:
  LFUCache(int capacity) {
    capacity_ = capacity;
    min_freq_ = 0;
  }

  int get(int key, int new_val = -1) {
    if (key_table_.find(key) == key_table_.end() || capacity_ == 0) {
      return -1;
    }
    int val = key_table_[key]->val, freq = key_table_[key]->freq;
    if (new_val != -1) {
        val = new_val;
    }
    Node new_item = {.val = val, .key = key, .freq = freq + 1};
    freq_table_[freq].erase(key_table_[key]);
    if (freq_table_[freq].size() == 0 && min_freq_ == freq) {
      min_freq_ = new_item.freq;
      freq_table_.erase(freq);
    }
    freq_table_[new_item.freq].push_front(new_item);
    key_table_[key] = freq_table_[new_item.freq].begin();
    return new_item.val;
  }

  void put(int key, int val) {
    if (capacity_ == 0) return;
    if (key_table_.find(key) == key_table_.end()) {
      if (key_table_.size() == capacity_) {
        key_table_.erase(freq_table_[min_freq_].back().key);
        freq_table_[min_freq_].pop_back();
        if (freq_table_[min_freq_].size() == 0) {
          freq_table_.erase(min_freq_);
        }
      }
      Node item = {.val = val, .key = key, .freq = 1};
      freq_table_[1].push_front(item);
      key_table_[key] = freq_table_[1].begin();
      min_freq_ = 1;
    } else {
      get(key, val);
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

