// https://oj.vnoi.info/problem/dquery
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct query {
    ll l, r, index;
    bool operator<(const query &any) const {
        if (r == any.r) return l < any.l;
        return r < any.r;
    }
};

struct segment_tree {
    vector<ll> tree;
    ll n;
    segment_tree(vector<ll> &arr) {
        n = arr.size();
        tree = vector<ll>(n << 2);
        build_tree(arr, 1, 1, n);
    }

    void build_tree(vector<ll> &nums, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        ll mid = start + ((end - start) >> 1);

        build_tree(nums, (node << 1), start, mid),
            build_tree(nums, (node << 1 | 1), mid + 1, end);

        tree[node] = tree[(node << 1)] + tree[(node << 1 | 1)];
    }

    void update(ll pos, ll val, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] += val;
            return;
        }

        ll mid = start + ((end - start) >> 1);

        if (pos <= mid) {
            update(pos, val, (node << 1), start, mid);
        }
        else {
            update(pos, val, (node << 1 | 1), mid + 1, end);
        }

        tree[node] = tree[(node << 1)] + tree[(node << 1 | 1)];
    }

    ll query(ll l, ll r, ll node, ll start, ll end) {
        if (l > end || r < start)
            return 0;
        if (l <= start && r >= end)
            return tree[node];

        ll mid = start + ((end - start) >> 1);

        return query(l, r, (node << 1), start, mid) + query(l, r, (node << 1 | 1), mid + 1, end);
    }

    void update(ll pos, ll val) {
        update(pos, val, 1, 1, n);
    }
    ll query(ll l, ll r) {
        return query(l, r, 1, 1, n);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    ll q;
    cin >> q;
    vector<query> queries;

    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        queries.push_back({a, b, i});
    }

    sort(queries.begin(), queries.end());

    unordered_map<ll, ll> last;

    vector<ll> b(n + 1);

    segment_tree seg(b);

    ll cur = 0;

    vector<pair<ll, ll>> ans;

    for (ll i = 1; i <= n; i++) {
        seg.update(i, 1);

        if (last.count(a[i]))
            seg.update(last[a[i]], -1);

        last[a[i]] = i;

        while (queries[cur].r == i && cur < queries.size()) {
            ans.push_back({queries[cur].index, seg.query(queries[cur].l, queries[cur].r)});
            cur++;
        }
    }

    sort(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i.second << '\n';

    return 0;
}