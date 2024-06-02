/* https://atcoder.jp/contests/dp/tasks/dp_b */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 1;
int n, k;
int cache[MAXN];

int ans(int i, int a[]) {
    if (i <= 1) {
        return cache[i];
    }

    if (cache[i] != -1) {
        return cache[i];
    }

    int res = INT_MAX;
    cache[i] = res;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0)
            cache[i] = min(cache[i], abs(a[i] - a[i - j]) + ans(i - j, a));
    }

    return cache[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    cin >> n >> k;
    int a[n];

    for (auto &i : a) {
        cin >> i;
    }

    cache[0] = 0;
    cache[1] = abs(a[1] - a[0]);

    cout << ans(n - 1, a);

    return 0;
}
