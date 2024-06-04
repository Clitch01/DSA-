/* https://cses.fi/problemset/task/1666/ */

#include <bits/stdc++.h>
using namespace std;

void _dfs(vector<vector<int>> &vertex, vector<bool> &vis, int node) {
    if (vis[node] == true) {
        return;
    }

    vis[node] = true;

    for (auto &i : vertex[node]) {
        _dfs(vertex, vis, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> answer;
    vector<vector<int>> vertex(n + 1);
    vector<bool> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            _dfs(vertex, vis, i);
            answer.push_back(i);
        }
    }

    cout << answer.size() - 1 << "\n";

    for (int i = 0; i < answer.size() - 1; i++) {
        cout << answer[i] << " " << answer[i + 1] << "\n";
    }

    return 0;
}