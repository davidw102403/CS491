#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <climits>

using namespace std;

int quick_changes(vector<string>& recitals, int i, int j) {
    string& r1 = recitals[i];
    vector<int> counts(26, 0);
    for (char c : r1) {
        counts[c - 'A']++;
    }
    int changes = 0;
    string& r2 = recitals[j];
    for (char c : r2) {
        changes += counts[c - 'A'] == 1;
    }
    return changes;
}

int main() {
    vector<string> recitals;

    int R;

    cin >> R;
    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        recitals.push_back(s);
    }
    sort(recitals.begin(), recitals.end());

    vector<vector<int>> adj(R, vector<int>(R, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            adj[i][j] = quick_changes(recitals, i, j);
        }
    }

    vector<int> indexes(R);
    for (int i = 0; i < R; i++) {
        indexes[i] = i;
    }

    int res = INT_MAX;
    do {
        int cur_changes = 0;
        bool set = true;
        for (int i = 0; i < R - 1; i++) {
            cur_changes += adj[indexes[i]][indexes[i + 1]];
            if (cur_changes >= res) {
                set = false;
                break;
            }
        }
        if (set) {
            res = cur_changes;
        }
    } while (next_permutation(indexes.begin(), indexes.end()));

    cout << res << endl;
}