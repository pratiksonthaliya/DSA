class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree() {}
    
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Query: return the leftmost index in [0, n-1] where value >= val
    int query(int val) {
        return query(1, 0, n - 1, val);
    }

    int query(int node, int start, int end, int val) {
        if (tree[node] < val) return -1; // not found in this segment
        if (start == end) return start;

        int mid = (start + end) / 2;
        if (tree[2 * node] >= val)
            return query(2 * node, start, mid, val);
        else
            return query(2 * node + 1, mid + 1, end, val);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree sg(baskets);

        int unplaced = 0;
        for (int fruit : fruits) {
            int idx = sg.query(fruit);
            if (idx != -1) {
                sg.update(idx, -1); // mark basket as used
            } else {
                unplaced++;
            }
        }
        return unplaced;
    }
};