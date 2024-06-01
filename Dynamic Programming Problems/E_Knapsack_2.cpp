#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<pair<ll, ll>> arr;
ll cache[101][1000001];

ll dp(int index, ll weight) {
    if (index >= n)
        return (!weight) ? 0 : INT_MAX;

    else if (cache[index][weight] != -1)
        return cache[index][weight];

    else
        return cache[index][weight] = min(dp(index + 1, weight - arr[index].second) + arr[index].first,
                                          dp(index + 1, weight));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    arr.resize(n);

    memset(cache, -1, sizeof(cache));

    ll v_max(0);
    ll v_min((int)1e9);
    for (auto &i : arr) {
        cin >> i.first >> i.second;
        v_max += i.second;
        v_min = min(v_min, i.second);
    }

    for (int i = v_max; i >= v_min; i--) {
        if (dp(0, i) <= k) {
            return cout << i, 0;
        }
    }

    return 0;
}
