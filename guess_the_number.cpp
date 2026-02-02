#include <iostream>

using namespace std;

void solve() {
    int l = 1;
    int r = 1000;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << mid << endl;
        string response;
        cin >> response;
        if (response == "lower") {
            r = mid - 1;
        } else if (response == "higher") {
            l = mid + 1;
        } else {
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}