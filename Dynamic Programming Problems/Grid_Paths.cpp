/* https://cses.fi/problemset/result/9385478/ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> s(n);

    for (auto &i : s) {
        cin >> i;
    }

    int cache[n + 1][n + 1] = {};
    cache[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1][j - 1] == '*')
                cache[i][j] = 0;
            else if (i == 1 && j == 1)
                continue;
            else
                cache[i][j] = cache[i - 1][j] % MOD + cache[i][j - 1] % MOD;
            cache[i][j] %= MOD;
        }
    }
    cout << cache[n][n];

    return 0;
}
