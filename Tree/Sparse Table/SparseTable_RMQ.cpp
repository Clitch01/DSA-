#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> SparseTable;

int RangeMinimumQueries(int l, int r) {
    int u = log2(r - l + 1);
    return min(SparseTable[l][u], SparseTable[r - (1 << u) + 1][u]);
}

void PreCompute(int n, int k) {
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            SparseTable[i][j] = min(SparseTable[i][j - 1], SparseTable[i + (1 << (j - 1))][j - 1]);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int u = log2(n);
    SparseTable.resize(n + 1, vector<int>(u + 1));

    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        SparseTable[i][0] = value;
    }

    PreCompute(n, k);

    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << RangeMinimumQueries(l, r) << '\n';
    }
}
