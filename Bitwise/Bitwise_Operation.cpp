#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class BitOperation {
   public:
    int FlipToZero(int n, int k) {
        return n & ~(1 << (k - 1));  // Flip the k-th bit of n to 0
    }
    int FlipToOne(int n, int k) {
        return n | (1 << (k - 1));  // Flip the k-th bit of n to 1
    }
    int FlipBit(int n, int k) {
        return n ^ (1 << (k - 1));  // Flip the k-th bit of n
    }
    bool CheckBit(int n, int k) {
        return n & (1 << (k - 1));  // Check the k-th bit of n
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    BitOperation bitwise;

    cout << bitwise.FlipToZero(n, k);
    cout << "\n";
    cout << bitwise.FlipToOne(n, k);
    cout << "\n";
    cout << bitwise.FlipBit(n, k);
    cout << "\n";
    cout << bitwise.CheckBit(n, k);

    return 0;
}