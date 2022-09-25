class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        v_ = vector<int>(k + 1);
        front_ = 0;
        rear_ = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        ++rear_;
        if (rear_ == v_.size()) rear_ = 0;
        v_[rear_] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front_++;
        if (front_ == v_.size()) front_ = 0;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return v_[front_];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return v_[rear_];
    }

    bool isEmpty() {
        int n = v_.size();
        return (rear_ - front_ + n) % n == n - 1;
    }

    bool isFull() {
        int n = v_.size();
        return (rear_ - front_ + n) % n == n - 2;
    }
private:
    vector<int> v_;
    int front_, rear_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */