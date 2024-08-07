class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        if (small.size() > 0 && large.size() > 0 && small.top() > large.top()) {
            int val = small.top();
            small.pop();
            large.push(val);
        }

        if (small.size() > large.size() + 1) {
            int val = small.top();
            small.pop();
            large.push(val);
        }
        if (large.size() > small.size() + 1) {
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        else if (small.size() < large.size()) {
            return large.top();
        }
        else {
            return (double)(small.top() + large.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */