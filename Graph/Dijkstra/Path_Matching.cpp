// https://oj.vnoi.info/problem/trafficn
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;

struct Node {
    ll index;
    ll lenght;
    bool operator<(const Node &any) const {
        return lenght > any.lenght;
    }
};

vector<ll> dijkstra(vector<vector<Node>> graph, int n, int start) {
    vector<ll> vertex(n + 1, INF);
    vertex[start] = 0;

    priority_queue<Node> queue;
    queue.push({start, 0});

    while (!queue.empty()) {
        Node cur = queue.top();
        queue.pop();

        if (vertex[cur.index] < cur.lenght)
            continue;
        for (auto i : graph[cur.index]) {
            if (i.lenght + cur.lenght < vertex[i.index]) {
                vertex[i.index] = i.lenght + cur.lenght;
                queue.push({i.index, vertex[i.index]});
            }
        }
    }
    return vertex;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;

        vector<vector<Node>> MainGraph(n + 1);
        vector<vector<Node>> SubGraph(n + 1);
        vector<ll> path;
        vector<ll> reverse_path;

        ll d, c, l;

        while (m--) {
            cin >> d >> c >> l;
            MainGraph[d].push_back({c, l});
            SubGraph[c].push_back({d, l});
        }

        path = dijkstra(MainGraph, n, s);
        reverse_path = dijkstra(SubGraph, n, t);

        ll ans = path[t];

        while (k--) {
            cin >> d >> c >> l;
            ans = min({ans, path[d] + l + reverse_path[c], path[c] + l + reverse_path[d]});
        }

        cout << (ans >= INF ? -1 : ans) << "\n";
    }

    return 0;
}
