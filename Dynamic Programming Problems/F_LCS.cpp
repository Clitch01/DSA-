/* https://atcoder.jp/contests/dp/tasks/dp_f */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1));

    for (ll i = s.size() - 1; i >= 0; i--) {
        for (ll j = t.size() - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    string ans;
    ll n = 0, m = 0;

    while (n < s.size() && m < t.size()) {
        if (s[n] == t[m]) {
            ans += s[n];
            n++;
            m++;
        } else if (dp[n][m + 1] > dp[n + 1][m])
            m++;
        else
            n++;
    }

    cout << ans;
    return 0;
}