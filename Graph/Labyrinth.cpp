/* https :  // cses.fi/problemset/task/1193/ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int f_direc[] = {-1, +1, 0, 0};
    int s_direc[] = {0, 0, -1, +1};
    char direction[] = {'U', 'D', 'L', 'R'};

    int n, m;
    cin >> n >> m;

    string s[n];
    vector<vector<char>> path(n, vector<char>(m, 0));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                start = {i, j};
            }
            if (s[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    queue<pair<int, int>> queue;
    queue.push(start);

    while (!queue.empty()) {
        pair<int, int> nix = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int x = nix.first + f_direc[i];
            int y = nix.second + s_direc[i];
            if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#' && !path[x][y]) {
                path[x][y] = direction[i];
                queue.push({x, y});
            }
        }
    }

    if (!path[end.first][end.second]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string result;
        while (start != end) {
            char c = path[end.first][end.second];
            result += c;
            if (c == 'U') end.first++;
            if (c == 'D') end.first--;
            if (c == 'L') end.second++;
            if (c == 'R') end.second--;
        }
        reverse(result.begin(), result.end());
        cout << result.size() << "\n"
             << result;
    }

    return 0;
}
