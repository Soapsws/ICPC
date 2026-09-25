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

    for (int v = 0; v < t; v++) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> prefix; // length n + 1
        prefix.push_back(0);
        for (int i = 1; i <= n; i++) {
            prefix.push_back(a[i-1] + prefix[i-1]);
        }

        // for (int i : prefix) cout << i << " ";

        for (int i = 0; i < q; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            long long lw = prefix[l - 1] - prefix[0];
            long long rw = prefix[n] - prefix[r];
            // cout << lw << " " << rw << '\n';
            long long result = lw + rw + k * (r - l + 1);
            if (result % 2 == 1) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }


    return 0;
}