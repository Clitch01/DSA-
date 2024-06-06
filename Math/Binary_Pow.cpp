// https://coder.husc.edu.vn/problem/spit0001

#include <bits/stdc++.h>
using namespace std;

// how to calculate a^b % MOD
const int MOD = 998244353;

long long BinPow(long long a, long long b) {
    if (!b) {
        return 1;
    }
    long long nums = BinPow(a % MOD, b / 2) % MOD;
    if (b & 1) {
        return nums % MOD * nums % MOD * a % MOD;
    } else {
        return nums % MOD * nums % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << BinPow(a % MOD, b) << "\n";
    }

    return 0;
}