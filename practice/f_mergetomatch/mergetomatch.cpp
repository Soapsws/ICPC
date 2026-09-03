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
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(m);
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (!(a.size() >= 2 * b.size())) {
            cout << "NO" << '\n';
            continue;
        } 

        bool possible = true;

        for (int i = 0; i < m; i++) {
            if (!(a[i] < b[i] && a[n - m + i] > b[i])) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }
    return 0;
}


   