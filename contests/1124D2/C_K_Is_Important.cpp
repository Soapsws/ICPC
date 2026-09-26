#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // greedy ??

    for (int v = 0; v < t; v++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1);
        // ONE INDEXED, IND[0] = 0
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int to_delete = n - (k - 1);
        int extremes = k - 1;

        long long sum = 0;

        if (extremes > n / 2) {
            extremes = n - extremes;
            // cout << "//" << extremes << "//";
        }

        // guaranteed deletes - bypassed if extremes > n/2
        for (int i = k; i <= n - k + 1; i++) {
            sum += a[i];
        }

        // pairwise selection delete maximum
        for (int i = extremes; i >= 1; i--) {
            int lower = i;
            int upper = n - i + 1;

            if (a[upper] > a[lower]) {
                sum += a[upper];
            } else {
                sum += a[lower];
            }
        }

        cout << sum << '\n';
    }


    return 0;
}