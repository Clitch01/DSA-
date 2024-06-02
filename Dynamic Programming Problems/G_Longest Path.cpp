/* https://atcoder.jp/contests/dp/tasks/dp_g */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[(int)1e5 + 1];
vector<int> cache((int)1e5 + 1, -1);

int dfs(int x) {
    if (cache[x] != -1) {
        return cache[x];
    }
    for (auto &i : node[x]) {
        cache[i] = dfs(i);
        cache[x] = max(cache[x], cache[i] + 1);
    }
    return cache[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
    }

    int result = INT_MIN;
    for (int i = 1; i <= (int)1e5; i++) {
        if (!node[i].empty())
            result = max(result, dfs(i) + 1);
    }

    cout << result;

    return false;
}