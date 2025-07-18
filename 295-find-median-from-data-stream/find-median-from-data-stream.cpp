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
        mxPQ.push(num);

        mnPQ.push(mxPQ.top());
        mxPQ.pop();

        if(mnPQ.size() > mxPQ.size()){
            mxPQ.push(mnPQ.top());
            mnPQ.pop();
        }
    }
    
    double findMedian() {
        
        //cout << mxPQ.size() << " " << mnPQ.size() << endl;

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