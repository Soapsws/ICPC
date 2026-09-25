#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k; 

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minimum = 100000000;

    int left = 0;
    int right = left + k - 1;
    int currsum = 0;

    for (int i = 0; i < left + k; i++) {
        currsum += a[i];
    }

    while (right < n) {
        minimum = min(minimum, currsum);
        currsum -= a[left];
        right++;
        left++;
        if (right >= n) break;
        currsum += a[right];
    }

    cout << minimum;

    return 0;
}