class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (false == que1.empty() && que1.top() < num) {
            que2.push(num);
        } else {
            que1.push(num);
        }
        adjust();
    }

    void adjust() {
        while (static_cast<int>(que1.size()) - static_cast<int>(que2.size()) > 1) {
            que2.push(que1.top());
            que1.pop();
        }
        while (static_cast<int>(que2.size()) - static_cast<int>(que1.size()) > 1) {
            que1.push(que2.top());
            que2.pop();
        }
    }
    
    double findMedian() {
        assert(static_cast<int>(que1.size()) - static_cast<int>(que2.size()) <= 1);
        assert(static_cast<int>(que2.size()) - static_cast<int>(que1.size()) <= 1);
        if (que1.size() == que2.size()) {
            assert(false == que1.empty());
            assert(false == que2.empty());
            return (que1.top() + que2.top()) / 2.0;
        } else {
            if (que1.size() > que2.size()) {
                return que1.top();
            } else {
                return que2.top();
            }
        }
    }
    std::priority_queue<int, std::vector<int>, std::less<int>> que1;    
    std::priority_queue<int, std::vector<int>, std::greater<int>> que2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

