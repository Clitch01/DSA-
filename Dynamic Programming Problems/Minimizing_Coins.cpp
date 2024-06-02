/* https://cses.fi/problemset/task/1634 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int cache[1000001];

int coin(int a[], int total) {
    if (!total) {
        return 0;
    }
    if (total < 0) {
        return INT_MAX;
    }
    if (cache[total] != -1) {
        return cache[total];
    }
    cache[total] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int ans = coin(a, total - a[i]);
        if (ans != INT_MAX) {
            cache[total] = min(cache[total], ans + 1);
        }
    }
    return cache[total];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> n >> k;
    int a[n + 1] = {0};

    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = coin(a, k);
    if (res == INT_MAX)
        return cout << -1, 0;
    cout << res;

    return 0;
}
