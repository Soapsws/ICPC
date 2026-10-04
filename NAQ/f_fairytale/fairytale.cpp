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
        int n;
        cin >> n;
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<bool> tags(4);
        for (int i : p) {
            int res = (i - 1) / 10;
            tags[res] = true;
        }

        int sol = 0;
        for (int i = 0; i < 4; i++) {
            if (tags[i] == true) sol++;
        }

        cout << sol << '\n';
    }


    return 0;
}