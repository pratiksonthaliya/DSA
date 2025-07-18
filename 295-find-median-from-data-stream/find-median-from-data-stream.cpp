class MedianFinder {
public:
    int sz;
    priority_queue<int> mxPQ;
    priority_queue<int, vector<int>, greater<int>> mnPQ;
    
    MedianFinder() {
        sz = 0;
    }
    
    void addNum(int num) {

        sz++;
        // PUSH 
        if(mxPQ.empty() || num <= mxPQ.top()){
            mxPQ.push(num);
        } else {
            mnPQ.push(num);
        }

        //REBALANCE
        if(mxPQ.size() < mnPQ.size()){
            mxPQ.push(mnPQ.top());
            mnPQ.pop();
        } else if(mxPQ.size() > mnPQ.size() + 1){
            mnPQ.push(mxPQ.top());
            mxPQ.pop();
        }

        // mxPQ.push(num);

        // mnPQ.push(mxPQ.top());
        // mxPQ.pop();

        // if(mnPQ.size() > mxPQ.size()){
        //     mxPQ.push(mnPQ.top());
        //     mnPQ.pop();
        // }
    }
    
    double findMedian() {
        if(sz&1) return mxPQ.top();
        return (mnPQ.top() + mxPQ.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */