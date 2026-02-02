#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;

    int components;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
        components = n;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return; 
        if (size[pa] > size[pb]) {
            swap(pa, pb);
        }
        parent[pa] = pb;
        size[pb] += size[pa];
        components--;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    DSU d(K);

    for (int j = 0; j < M; j++) {
        char rep = grid[0][j] - 'A';
        for (int i = 1; i < N; i++) {
            char c = grid[i][j] - 'A';
            d.unite(rep, c);
        }
    }

    cout << d.components << endl;
    return 0;
}