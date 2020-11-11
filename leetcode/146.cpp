#include <assert.h>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>
#include <list>
using namespace std;



class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (map_.find(key) == map_.end()) {
            return -1;
        }
        auto item = map_[key];
        auto ret = item.first;
        list_.erase(item.second);
        list_.push_front(key);
        map_[key] = std::make_pair(ret, list_.begin());
        return ret;
    }
    
    void put(int key, int value) {
        if (map_.find(key) == map_.end()) {
            list_.push_front(key);
            map_[key] = std::make_pair(value, list_.begin());
        } else {
            auto item = map_[key];
            auto ret = item.first;
            list_.erase(item.second);
            list_.push_front(key);
            map_[key] = std::make_pair(value, list_.begin());
        }
        if (list_.size() > capacity_) {
            map_.erase(list_.back());
            list_.pop_back();
        }
    }
    int capacity_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> map_;
    std::list<int> list_;
};

int main() {

}
