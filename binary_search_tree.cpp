#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int n) {
//         val = n;
//     }
// };

// TreeNode* insert(TreeNode* root, int val, int& depth) {
//     if (!root) {
//         return new TreeNode(val);
//     }

//     if (val > root->val) {
//         depth++;
//         root->right = insert(root->right, val, depth);
//     } else {
//         depth++;
//         root->left = insert(root->left, val, depth);
//     }

//     return root;
// }

// void solve() {  
//     int n;
//     cin >> n;

//     long long C = 0;

//     int r;
//     cin >> r;
//     TreeNode* root = new TreeNode(r);
//     cout << C << endl;

//     for (int i = 1; i < n; i++) {
//         int x;
//         cin >> x;
//         int d = 0;
//         insert(root, x, d);
//         C += d;
//         cout << C << endl;
//     }
// }

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long C = 0;

    map<int, int> depths; // val -> depth

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int d = 0;
        auto it = depths.lower_bound(x); // first entry in depths >= x

        if (it != depths.end()) {
            d = max(d, it->second + 1);
        }

        if (it != depths.begin()) {
            d = max(d, prev(it)->second + 1);
        }
        depths[x] = d;
        C += d;
        cout << C << endl;
    }
}

int main() {
    solve();
    return 0;
}