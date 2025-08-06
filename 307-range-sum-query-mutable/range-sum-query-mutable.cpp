class SegmentTree {
    vector<long long> tree;
    int n;

public:
    SegmentTree() {}
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;           // No overlap
        if (l <= start && end <= r) return tree[node]; // Total overlap
        int mid = (start + end) / 2;
        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }
};

class NumArray {   
public:
    SegmentTree sg;
    NumArray(vector<int>& nums) {
        sg = SegmentTree(nums);
    }
    
    void update(int index, int val) {
        sg.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return sg.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */