#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <numeric>
#include <climits>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int first = a[i];
        int second = a[i + 1];
        int third = a[i + 2];
        if (second - first > third - second) count++;
    }

    cout << count;

    return 0;
}