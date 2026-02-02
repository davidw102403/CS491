#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

void solve() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            double f;
            cin >> u >> v >> f;
            adj[u].push_back({v, f});
            adj[v].push_back({u, f});
        }

        priority_queue<pair<double, int>> pq; // max_heap

        vector<double> max_size(n, -1);
        max_size[0] = 1.0;

        pq.push({1.0, 0});

        while (!pq.empty()) {
            auto [cur_size, u] = pq.top(); pq.pop();

            if (cur_size < max_size[u]) continue;

            for (const auto& nei : adj[u]) {
                double new_size = cur_size * nei.second;
                if (new_size > max_size[nei.first]) {
                    max_size[nei.first] = new_size;
                    pq.push({new_size, nei.first});
                }
            }
        }
        cout << fixed << setprecision(4) << max_size[n - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}