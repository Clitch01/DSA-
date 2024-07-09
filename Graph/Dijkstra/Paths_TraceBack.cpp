// https://oj.vnoi.info/problem/floyd
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Nodes {
    int index;
    ll val;
    bool operator<(const Nodes &any) const {
        return val > any.val;
    }
};

void query(vector<vector<Nodes>> graph, bool &choosen, int &n, int &u, int &v) {
    priority_queue<Nodes> queue;
    queue.push({u, 0});

    vector<pair<int, int>> vertex(n + 1, {INT_MAX, -1});
    vertex[u].first = 0;

    while (!queue.empty()) {
        Nodes node = queue.top();
        queue.pop();

        if (node.val == vertex[node.index].first) {
            for (auto i : graph[node.index]) {
                if (i.val + node.val < vertex[i.index].first) {
                    vertex[i.index].first = i.val + node.val;
                    vertex[i.index].second = node.index;
                    queue.push({i.index, i.val + node.val});
                }
            }
        }
    }

    if (!choosen) {
        cout << vertex[v].first;
        return;
    }

    vector<int> res;
    int trace = v;

    while (trace != -1) {
        res.push_back(trace);
        trace = vertex[trace].second;
    }

    cout << res.size() << " ";
    for (vector<int>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
        cout << *it << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<Nodes>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        graph[x].push_back({y, v});
        graph[y].push_back({x, v});
    }

    while (q--) {
        bool choosen;
        int u, v;
        cin >> choosen >> u >> v;
        query(graph, choosen, n, u, v);
        cout << "\n";
    }
    //

    return 0;
}

