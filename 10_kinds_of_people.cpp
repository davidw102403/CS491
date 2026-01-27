#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return;

        if (size[root_x] <= size[root_y]) {
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        } else {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }

    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    DSU dsu(R * C);

    auto get_id = [&](int r, int c) {
        return r * C + c;
    };

    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int cur_id = get_id(i, j);
            char type = grid[i][j];
            for (auto [dr, dc] : dirs) {
                int new_r = i + dr;
                int new_c = j + dc;
                
                if (new_r < R && new_c < C && grid[new_r][new_c] == type) {
                    dsu.unite(cur_id, get_id(new_r, new_c));
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; r2--; c1--; c2--; // 1's based indexing to 0's based indexing

        if (grid[r1][c1] != grid[r2][c2]) {
            cout << "neither\n";
            continue;
        }

        if (dsu.sameSet(get_id(r1, c1), get_id(r2, c2))) {
            if (grid[r1][c1] == '1') {
                cout << "decimal\n";
            } else {
                cout << "binary\n";
            }
        } else {
            cout << "neither\n";
        }
    }
    return 0;
}