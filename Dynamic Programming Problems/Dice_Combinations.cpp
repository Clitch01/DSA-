/* https://cses.fi/problemset/result/9374318 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
int cache[(int)1e6 + 1] = {};

int dfs(int n) {
    if (n < 0) {
        return 0;
    }
    if (cache[n] != 0) {
        return cache[n];
    }
    if (!n) {
        return 1;
    }
    for (int i = 1; i <= 6; i++) {
        cache[n] += dfs(n - i);
        cache[n] %= MOD;
    }
    return cache[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << dfs(n);

    return 0;
}