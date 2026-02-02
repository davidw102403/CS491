#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    int n = s.size();
    vector<int> valid_k;
    

    for (int k = 1; k <= n; k++) {
        int a_wins = 0;
        int b_wins = 0;
        int a_cur = 0;
        int b_cur = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            a_cur += c == 'A';
            b_cur += c == 'B';
            if (a_cur == k) {
                a_wins++;
                a_cur = 0;
                b_cur = 0;
            } else if (b_cur == k) {
                b_wins++;
                a_cur = 0;
                b_cur = 0;
            }       
        }
        if (a_wins > b_wins) {
            valid_k.push_back(k);
        }
    }

    cout << valid_k.size() << endl;
    for (int vk : valid_k) {
        cout << vk << " ";
    }

    return 0;
}