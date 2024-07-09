// https://oj.vnoi.info/problem/qbschool
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int index;
    ll lenght;
    bool operator<(const Node& any) const {
        return lenght > any.lenght;
    }
};

void dijkstra(vector<vector<Node>> graph, int n) {
    vector<pair<ll, ll>> vertex(n + 1, {LLONG_MAX, 0});
    vertex[1].first = 0;
    vertex[1].second = 1;

    priority_queue<Node> queue;
    queue.push({1, 0});

    while (!queue.empty()) {
        Node cur = queue.top();
        queue.pop();

        if (vertex[cur.index].first < cur.lenght) continue;
        for (auto i : graph[cur.index]) {
            if (i.lenght + cur.lenght < vertex[i.index].first) {
                vertex[i.index].first = i.lenght + cur.lenght;
                vertex[i.index].second = vertex[cur.index].second;
                queue.push({i.index, vertex[i.index].first});
            }
			else if (i.lenght + cur.lenght == vertex[i.index].first) {
                vertex[i.index].second += vertex[cur.index].second;
            }
        }
    }

    cout << vertex[n].first << " " << vertex[n].second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<Node>> graph(n + 1);

    while (m--) {
        int k, u, v;
        ll l;
        cin >> k >> u >> v >> l;
        graph[u].push_back({v, l});
        if (k == 2)
            graph[v].push_back({u, l});
    }

    dijkstra(graph, n);

    return 0;
}
