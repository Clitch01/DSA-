#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n;
    int a[(int)log2(n) + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a[0][i] = val;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; (j + (1 << i) - 1) <= n; j++) {
            a[i][j] = __gcd(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int u = log2(r - l + 1);
        cout << __gcd(a[u][l], a[u][r - (1 << u) + 1]) << "\n";
    }
}
