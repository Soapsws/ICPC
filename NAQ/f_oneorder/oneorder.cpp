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

    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> routine(m);
        bool pos = true;
        int good = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                cout << -1 << '\n';
                pos = false;
                break;
            }
            if (a + 1 == b) good++;
            routine.push_back({a, b});
        }
        if (!pos) continue;
        cout << (n - 1) - good << '\n';
    }


    return 0;
}