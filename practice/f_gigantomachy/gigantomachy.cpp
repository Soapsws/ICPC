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

    for (int i = 0; i < t; i++) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int ra = 0;
        for (int i = 0; i < n - 1; i++) {
            ra += a[i] - a[i+1] + 1;
        }
        ra += a[n - 1];

        int rb = 0;
        for (int i = 0; i < m - 1; i++) {
            rb += b[i] - b[i+1] + 1;
        }
        rb += b[m - 1];

        if (ra >= rb) cout << 1 << '\n';
        else cout << 2 << '\n';

    }
    return 0;
}