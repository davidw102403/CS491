#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

vector<long long> dijkstra(int start, int n, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> max_dist(n, 1e18);
    pq.push({0, start});
    max_dist[start] = 0;

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > max_dist[cur]) continue;
        
        for (auto& [nei, nei_dist] : adj[cur]) {
            long long new_dist = dist + nei_dist;
            if (new_dist < max_dist[nei]) {
                max_dist[nei] = new_dist;
                pq.push({new_dist, nei});
            }
        }
    }

    return max_dist;
}

void solve() {
    int P, T;
    cin >> P >> T;
    vector<vector<pair<int, int>>> adj(P);

    vector<tuple<int, int, int>> edges;

    int p1, p2, l;
    for (int i = 0; i < T; i++) {
        cin >> p1 >> p2 >> l;
        adj[p1].push_back({p2, l});
        adj[p2].push_back({p1, l});
        edges.push_back({p1, p2, l});
    }

    vector<long long> dist_from_start = dijkstra(0, P, adj);
    vector<long long> dist_from_end = dijkstra(P-1, P, adj);

    long long shortest_length = dist_from_start[P - 1];

    long long total_len = 0;

    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        bool on_forward = dist_from_start[u] + w + dist_from_end[v] == shortest_length;
        bool on_backward = dist_from_start[v] + w + dist_from_end[u] == shortest_length;

        if (on_forward || on_backward) {
            total_len += w;
        }
    }

    cout << total_len * 2 << endl;
}

int main() {
    solve();
    return 0;
}