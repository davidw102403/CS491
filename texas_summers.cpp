#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> index_to_pt(n + 2);

    for (int i = 0; i < n; i++) {
        cin >> index_to_pt[i].first >> index_to_pt[i].second;
    }

    int dorm_idx = n;
    int class_idx = n + 1; 
    cin >> index_to_pt[dorm_idx].first >> index_to_pt[dorm_idx].second;
    cin >> index_to_pt[class_idx].first >> index_to_pt[class_idx].second;
 
    vector<vector<pair<long long, int>>> adj(n + 2); // index to {dist, index}
    
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            auto& [x1, y1] = index_to_pt[i];
            auto& [x2, y2] = index_to_pt[j];

            long long dist = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
            adj[i].push_back({dist, j});
            adj[j].push_back({dist, i});
        }
    }

    // dijkstras
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> max_dist(n + 2, LLONG_MAX);
    vector<int> parent(n + 2, -1);
    max_dist[dorm_idx] = 0;
    pq.push({0, dorm_idx});
    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();
        if (dist > max_dist[cur]) continue;
        if (cur == class_idx) break;

        for (auto& [nei_dist, nei] : adj[cur]) {
            long long new_dist = dist + nei_dist;
            if (new_dist < max_dist[nei]) {
                max_dist[nei] = new_dist;
                pq.push({new_dist, nei});
                parent[nei] = cur;
            }
        }
    }

    vector<int> path;
    int cur = class_idx;

    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    bool visited = false;
    for (int i : path) {
        if (i < n) {
            cout << i << endl;
            visited = true;
        }
    }

    if (!visited) {
        cout << "-" << endl;
    }
}

int main() {
    solve();
    return 0;
}