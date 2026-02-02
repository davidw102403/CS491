#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int p;
    cin >> p;
    while (p--) {
        int k;
        cin >> k;
        
        vector<int> students(20);
        for (int i = 0; i < 20; i++) {
            cin >> students[i];
        }

        int res = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < i; j++) {
                if (students[j] > students[i]) {
                    res++;
                }
            }
        }
        cout << k << " " << res << endl;
    }
}

int main() {
    solve();
    return 0;
}