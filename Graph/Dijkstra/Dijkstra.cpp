#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Nodes {
    int index;
    ll value;
    bool operator<(const Nodes &any) const {
        return value > any.value;
    }
};

vector<ll> ShortestPath(vector<vector<Nodes>> vertex, int n) {
    vector<ll> locate(n + 1, LLONG_MAX);
    locate[1] = 0;

    priority_queue<Nodes> queue;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({1, 0});

    while (!queue.empty()) {
        Nodes u = queue.top();
        queue.pop();
        if (u.value == locate[u.index]) {
            for (auto i : vertex[u.index]) {
                if (u.value + i.value < locate[i.index]) {
                    locate[i.index] = u.value + i.value;
                    queue.push({i.index, u.value + i.value});
                }
            }
        }
    }

    return locate;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<Nodes>> vertex(n + 1);

    while (m--) {
        int x, y;
        ll v;
        cin >> x >> y >> v;
        vertex[x].push_back({y, v});
    }

    vector<ll> path = ShortestPath(vertex, n);
    for (int i = 1; i <= n; i++) {
        cout << path[i] << " ";
    }

    return 0;
}
