#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // step 1 -> find number of equal neighbors for 0s and 1s
    // step 2 -> if they differ by more than 1 you can't fulfill the alternating deletion constraint
    // step 3 -> else just go through and delete until it's alternating

    int t;
    cin >> t;

    // bad edges (fodder for deletion if not equal to its neighbor)

    for (int l = 0; l < t; l++) {

        int n;
        cin >> n;
        string s;
        cin >> s;

        int zeros = count(s.begin(), s.end(), '0');
int ones = n - zeros;

if (abs(zeros - ones) > 2) {
    cout << -1 << '\n';
    continue;
}

int badzeros = 0, badones = 0;

for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == s[i + 1]) {
        if (s[i] == '0') ++badzeros;
        else ++badones;
    }
}

if (abs(badzeros - badones) <= 1) {
    cout << badzeros + badones << '\n';
} else {
    cout << 2 * max(badzeros, badones) - 1 << '\n';
}
    }



    return 0;
}
