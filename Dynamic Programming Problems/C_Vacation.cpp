/* https://atcoder.jp/contests/dp/tasks/dp_c */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cache[(ll)(1e5 + 1)][3] = {};

ll dp(vector<vector<ll>> &a, ll i, ll j) {
    if (i == a.size()) {
        return 0;
    }
    if (cache[i][j]) {
        return cache[i][j];
    }
    ll res = 0;
    for (ll k = 0; k < 3; k++) {
        if (k == j)
            continue;
        res = max(res, dp(a, i + 1, k) + a[i][j]);
    }
    return cache[i][j] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(3));

    for (auto &i : a) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < 3; i++) {
        ans = max(ans, dp(a, 0, i));
    }
    cout << ans;

    return 0;
}