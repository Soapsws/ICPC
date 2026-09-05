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
    
    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;
        vector<int> a(n);

        int firstodd = -1;
        int firsteven = -1;

        int total_odds = 0;
        int total_evens = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                if (firsteven == -1) {
                    firsteven = i;
                }
                total_evens++;
            }
            else {
                if (firstodd == -1) {
                    firstodd = i;
                }
                total_odds++;
            }
        }

        // cout << firstodd << " " << firsteven << " " << total_odds << " " << total_evens << '\n';

        int maxfamily = 0;

        // evens
        if (firsteven != -1) {
            int tent = 0;
            for (int i = firsteven; i < n; i++) {
                if (a[i] % 2 == 1) continue;
                if ((abs(a[i] - a[firsteven]) / 2) % 2 == 0) {
                    // cout << (a[i] - a[firsteven]) / 2 << '\n';
                    tent++;
                }
            }
            // cout << tent << '\n';
            maxfamily = max(maxfamily, max(tent, total_evens - tent));
        }

        maxfamily = max(total_odds, maxfamily);
        cout << maxfamily << '\n';
    }

    return 0;
}