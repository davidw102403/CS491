#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;
const double PI = acos(-1.0);

void solve() {
    int P;
    cin >> P;
    while (P--) {
        int N, F;
        cin >> N >> F;
        F++;
        
        double max_vol = 0;
        vector<double> volumes(N);
        for (int i = 0; i < N; i++) {
            int r;
            cin >> r;
            volumes[i] = PI * r * r;
            max_vol = max(max_vol, volumes[i]);
        }
        // return true if can give every person a piece with volume mid
        auto check = [&](double mid) {
            int pieces = 0;
            for (double v : volumes) {
                pieces += floor(v / mid);
            }
            return pieces >= F;
        };


        double l = 0;
        double r = max_vol;

        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2;
            (check(mid) ? l : r) = mid;
        }
        cout << fixed << setprecision(4) << l << endl;
    }

}

int main() {
    solve();
    return 0;
}