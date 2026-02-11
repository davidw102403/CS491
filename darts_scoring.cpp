#include <iostream>
#include <vector>
#include <string> 

using namespace std;

class Solution {
public:
    vector<vector<string>> combos;

    void solve() {
        int n; 
        cin >> n;
        vector<string> cur;
        dfs(0, n, cur, 0);
        cout << combos.size() << endl;
        for (auto& combo : combos) {
            cout << combo.size() << endl;
            for (auto& s : combo) {
                cout << s << endl;
            }
        }
    }

    void dfs(int total, int target, vector<string>& cur, int tries) {
        if (tries > 3 || total > target) return;

        if (total == target) {
            combos.push_back(cur);
            return;
        }

        for (int i = 1; i <= 20; i++) {
            cur.push_back("Single " + to_string(i));
            dfs(total + i, target, cur, tries + 1);
            cur.pop_back();
            cur.push_back("Double " + to_string(i));
            dfs(total + i * 2, target, cur, tries + 1);
            cur.pop_back();
            cur.push_back("Triple " + to_string(i));
            dfs(total + i * 3, target, cur, tries + 1);
            cur.pop_back();
        }
        cur.push_back("Outer bullseye");
        dfs(total + 25, target, cur, tries + 1);
        cur.pop_back();
        cur.push_back("Bullseye");
        dfs(total + 50, target, cur, tries + 1);
        cur.pop_back();
    }
};

int main() {
    Solution s;
    s.solve();
    return 0;
}