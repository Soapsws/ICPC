#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {
        int l, r;
        cin >> l >> r;

        long long dist = r - l + 1;
        long long solution = 0;

        long long lowbound = 0;
        long long highbound = r;

        if (l == r) {
            cout << 1 << '\n';
            continue;
        }

        while (lowbound <= highbound) {
            long long med = (lowbound + highbound) / 2;
            long long conv = med - 1;
            long long test = (conv) * (conv + 1) / 2 + 1;
            if (test == dist) {
                solution = med;
                break;
            } else if (test > dist) {
                highbound = med - 1;
            } else {
                solution = med;
                lowbound = med + 1;
            }
        }

        cout << solution << '\n';
    }


    return 0;
}