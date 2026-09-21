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
        string s;
        cin >> s;

        vector<int> prefixzeros(n);
        vector<int> prefixones(n);

        prefixzeros[0] = s[0] == '0' ? 1 : 0;
        prefixones[0] = s[0] == '1' ? 1 : 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                prefixzeros[i] = prefixzeros[i - 1] + 1;
                prefixones[i] = prefixones[i - 1];
            } else {
                prefixones[i] = prefixones[i - 1] + 1;
                prefixzeros[i] = prefixzeros[i - 1];
            }
        }

        // DEBUG

        // for (int i : prefixzeros) {
        //     cout << i << " ";
        // }

        // Case: first is [1]
        if (s[0] == '1') {
            // cout << "first is one";
            int sol = prefixzeros[n - 1];
            cout << sol << '\n';
            continue;
        }

        int minops = n + 10;

        // Case: first is [0]
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                int m = prefixones[i] + (prefixzeros[n - 1] - prefixzeros[i]);
                minops = min(m, minops);
            } else {
                if (i == 0) continue;
                // i is at least 1
                int m = prefixones[i - 1] + (prefixzeros[n - 1] - prefixzeros[0]);
                minops = min(m, minops);
            }
        }

        cout << minops << '\n';
    }


    return 0;
}