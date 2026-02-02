#include <iostream>
#include <vector>
using namespace std;

long long res = 0;

void merge(vector<int>& nums, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left_arr(n1), right_arr(n2);

    for (int i = 0; i < n1; i++) {
        left_arr[i] = nums[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            nums[k] = left_arr[i];
            i++;
            k++;
        } else {
            nums[k] = right_arr[j];
            j++;
            k++;
            res += (n1 - i);
        }
    }

    while (i < n1) {
        nums[k] = left_arr[i];
        k++;
        i++;
    }
    
    while (j < n2) {
        nums[k] = right_arr[j];
        k++;
        j++;
    }
}

void merge_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    int d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        nums.push_back(d);
    }
    merge_sort(nums, 0, n - 1);
    cout << res << endl;
    return 0;
}