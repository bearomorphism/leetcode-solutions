class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (smaller_.size() == bigger_.size()) smaller_.push(num);
        else bigger_.push(num);

        while (!smaller_.empty() && !bigger_.empty() && smaller_.top() > bigger_.top()) {
            int a = smaller_.top(), b = bigger_.top();
            smaller_.pop();
            bigger_.pop();
            smaller_.push(b);
            bigger_.push(a);
        }
    }

    double findMedian() {
        if (smaller_.size() == bigger_.size()) {
            return (double(smaller_.top()) + double(bigger_.top())) / 2;
        }
        return smaller_.top();
    }
private:
    priority_queue<int> smaller_{};
    priority_queue<int, vector<int>, greater<int>> bigger_{};
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */