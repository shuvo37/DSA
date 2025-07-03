#include <vector>
#include <functional>
#include <cmath>

template<typename T, typename U = T>
class SegmentTree {
private:
    int size;               // Size of the input array
    std::vector<T> tree;    // The segment tree
    T default_value;        // Default value for out-of-bound queries
    std::function<T(T, T)> combine; // Function to combine two segments

    // Function to build the tree
    void build(const std::vector<U>& arr, int node, int left, int right) {
        if (left == right) {
            tree[node] = T(arr[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        build(arr, 2 * node + 1, left, mid);
        build(arr, 2 * node + 2, mid + 1, right);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Function to update a value in the tree
    void update(int node, int left, int right, int index, U value) {
        if (left == right) {
            tree[node] = T(value);
            return;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid) {
            update(2 * node + 1, left, mid, index, value);
        } else {
            update(2 * node + 2, mid + 1, right, index, value);
        }
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Function to query the tree
    T query(int node, int node_left, int node_right, int query_left, int query_right) {
        if (query_right < node_left || node_right < query_left) {
            return default_value;
        }
        if (query_left <= node_left && node_right <= query_right) {
            return tree[node];
        }
        int mid = node_left + (node_right - node_left) / 2;
        T left_val = query(2 * node + 1, node_left, mid, query_left, query_right);
        T right_val = query(2 * node + 2, mid + 1, node_right, query_left, query_right);
        return combine(left_val, right_val);
    }

public:
    SegmentTree(const std::vector<U>& arr, T default_value, std::function<T(T, T)> combine)
        : size(arr.size()), default_value(default_value), combine(combine) {
        int height = (int)ceil(log2(size));
        int tree_size = 2 * (int)pow(2, height) - 1;
        tree.resize(tree_size, default_value);
        build(arr, 0, 0, size - 1);
    }

    // Update the value at index
    void update(int index, U value) {
        if (index < 0 || index >= size) return;
        update(0, 0, size - 1, index, value);
    }

    // Query the range [left, right]
    T query(int left, int right) {
        if (left > right || left < 0 || right >= size) return default_value;
        return query(0, 0, size - 1, left, right);
    }
};
