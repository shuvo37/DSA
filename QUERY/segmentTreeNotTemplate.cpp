#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    // Constructor to initialize segment tree
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // Safe size for segment tree
        build(arr, 0, 0, n - 1);
    }

    // Build the segment tree
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Query for minimum in range [l, r]
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX; // No overlap
        }
        if (l <= start && end <= r) {
            return tree[node]; // Total overlap
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int leftMin = query(2 * node + 1, start, mid, l, r);
        int rightMin = query(2 * node + 2, mid + 1, end, l, r);
        return min(leftMin, rightMin);
    }

    // Update a value at index idx to val
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
};

int main() {
    vector<int> arr = {5, 2, 6, 3, 1, 7};
    SegmentTree st(arr);

    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl; // Output: 1

    st.update(3, 0); // Update index 3 to value 0
    cout << "After update, minimum in range [1, 4]: " << st.query(1, 4) << endl; // Output: 0

    return 0;
}
