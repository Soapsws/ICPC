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
        int n, k;
        cin >> n >> k;

        if (k < n || k >= n + n) {
            cout << -1 << '\n';
            continue;
        }

        // num stacked
        int m = k - n;

        // initialize diagonal
        vector<vector<int>> b(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            b[i][i] = i + 1;
        }

        for (int i = 1; i <= m; i++) {
            int temp = b[i][i];
            b[i][i] = 0;
            b[0][i] = temp;
        }

        int tick = n + 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 0) {
                    b[i][j] = tick;
                    tick++;
                }
                cout << b[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}