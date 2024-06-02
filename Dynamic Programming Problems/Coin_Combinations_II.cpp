/* https://cses.fi/problemset/task/1636 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &i : a) {
        cin >> i;
    }
    int cache[n + 1][k + 1];
    memset(cache, 0, sizeof(cache));
    cache[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cache[i][j] += cache[i - 1][j];
            cache[i][j] %= MOD;
            if ((j - a[i - 1]) >= 0)
                cache[i][j] += cache[i][j - a[i - 1]];
            cache[i][j] %= MOD;
        }
    }
    cout << cache[n][k];

    return 0;
}