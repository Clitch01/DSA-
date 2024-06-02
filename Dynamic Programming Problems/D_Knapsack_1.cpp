/* https://atcoder.jp/contests/dp/tasks/dp_d */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cache[101][(int)1e5 + 1];

ll dp(vector<pair<ll, ll>> &arr, ll idx, ll k) {
    if (idx < 0 || k == 0) {
        return 0;
    }
    if (cache[idx][k] != -1) {
        return cache[idx][k];
    }
    if (k >= arr[idx].first) {
        return cache[idx][k] = max(arr[idx].second + dp(arr, idx - 1, k - arr[idx].first), dp(arr, idx - 1, k));
    }
    return cache[idx][k] = dp(arr, idx - 1, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);

    for (auto &i : arr) {
        cin >> i.first >> i.second;
    }

    cout << dp(arr, n - 1, k);

    return 0;
}
