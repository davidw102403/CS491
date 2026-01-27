#include <vector>
#include <iostream>

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

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    char op;
    int a, b;

    for (int i = 0; i < Q; i++) {
        cin >> op >> a >> b;
        if (op == '=') {
            dsu.unite(a, b);
        } else if (op == '?') {
            if (dsu.sameSet(a, b)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    return 0;
}