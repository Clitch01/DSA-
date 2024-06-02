/* https://cses.fi/problemset/task/1635 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int n, k;
int cache[(int)1e6 + 1] = {};
int arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cache[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= arr[j]) {
                cache[i] += cache[i - arr[j]];
                cache[i] %= MOD;
            }
        }
    }
    cout << cache[k];

    return 0;
}