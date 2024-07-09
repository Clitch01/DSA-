
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Segment_Tree {
   private:
    vector<T> node;
    vector<int> a;

   public:
    Segment_Tree(int size) {
        a.resize(size + 1);
        node.resize(size << 2);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            node[id] = a[l];
            return;
        }

        int mid = l + ((r - l) >> 1);

        build((id << 1), l, mid);
        build((id << 1) + 1, mid + 1, r);

        node[id] = node[(id << 1)] + node[(id << 1) + 1];
    }

    T get(int id, int l, int r, int &u, int &v) {
        if (v < l || u > r) {
            return 0;
        }

        if (u <= l && v >= r) {
            return node[id];
        }

        int mid = l + ((r - l) >> 1);

        return get(id << 1, l, mid, u, v) +
               get((id << 1) + 1, mid + 1, r, u, v);
    }

    void update(int id, int l, int r, int &pos, int &val) {
        if (pos < l || pos > r) {
            return;
        }

        if (l == r) {
            node[id] = val;
            a[pos] = val;
            return;
        }

        int mid = l + ((r - l) >> 1);

        update(id << 1, l, mid, pos, val),
            update((id << 1) + 1, mid + 1, r, pos, val);

        node[id] = node[id << 1] + node[(id << 1) + 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    Segment_Tree<long long> tree(n);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree.update(1, 1, n, i, x);
    }

    while (q--) {
        int x;
        cin >> x;
        int a, b;
        cin >> a >> b;
        if (x == 1) {
            tree.update(1, 1, n, a, b);
        } else {
            cout << tree.get(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}
