#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// phi n luon be hon chinh no

int totient(int n) {
    int result(n);
    // phan tich thua so nguyen to
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            while (!(n % i)) {
                n /= i;
            }
            // ta tru result^(-1) 
            result -= (result / i);
        }
    }
    if (n != 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << totient(100);
}
