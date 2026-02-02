#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>

using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    vector<int> bottoms;
    vector<int> tops;
    int n, h;
    cin >> n >> h;
    
    int x, y;
    for (int i = 0; i < n; i += 2) {
        cin >> x;
        bottoms.push_back(x);
        cin >> y;
        tops.push_back(y);
    }

    sort(bottoms.begin(), bottoms.end());
    sort(tops.begin(), tops.end());

    int min_res = INT_MAX;
    int num_valid = 0;

    for (int j = 1; j <= h; j++) {
        int bottoms_hit = bottoms.size() - lowerBound(bottoms, j);
        int h2 = h - j + 1;
        int tops_hit = tops.size() - lowerBound(tops, h2); 
        
        int total = bottoms_hit + tops_hit;

        if (total < min_res) {
            min_res = total;
            num_valid = 1; 
        } else if (total == min_res) {
            num_valid++;
        }
    }
    cout << min_res << " " << num_valid;
    
    return 0;
}