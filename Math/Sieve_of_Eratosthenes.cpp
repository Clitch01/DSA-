#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(nullptr);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    bool prime[n + 1];
    prime[1] = 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (!prime[i])
            for (int j = i * i; j <= n; j += i) {
                prime[j] = true;
            }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!prime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}