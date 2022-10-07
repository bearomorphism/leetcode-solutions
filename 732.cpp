class MyCalendarThree {
public:
    MyCalendarThree() {
        point_ = {};
    }

    int book(int start, int end) {
        point_[start]++;
        point_[end]--;

        int ans{0}, cur{0};
        for (auto &p: point_) {
            cur += p.second;
            ans = max(ans, cur);
        }
        return ans;
    }
private:
    map<int, int> point_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */