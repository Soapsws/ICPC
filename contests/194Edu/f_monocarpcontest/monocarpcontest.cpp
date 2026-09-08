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

        int ec = 0;
        int hc = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) ec++;
            else hc++;
        }

        if (ec < 2) {
            cout << -1 << '\n';
            continue;
        }

        int firstauto = a[0] == 0 ? 1 : 0;
        int lastauto = a[n-1] == 0 ? 1 : 0;

        cout << 2 - firstauto - lastauto << '\n';
    }


    return 0;
}