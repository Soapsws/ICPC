#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> stores(n);
    for (int i = 0; i < n; i++) {
        cin >> stores[i];
    }

    vector<long long> regpref(n);
    vector<long long> abspref(n);

    regpref[0] = stores[0];
    abspref[0] = abs(stores[0]);
    for (int i = 1; i < n; i++) {
        regpref[i] = regpref[i - 1] + stores[i];
        abspref[i] = abspref[i - 1] + abs(stores[i]);
    }

    long long maxprofit = 0;

    // separate for i = 0
    for (int j = 0; j < n; j++) {
        if (maxprofit < 2 * regpref[j] + (abspref[n - 1] - abspref[j])) {
            maxprofit = 2 * regpref[j] + (abspref[n - 1] - abspref[j]);
        }
    }

    int lp = 0;
    int rp = 1;

    while (lp < n && rp < n) {
        lp++;
        while(lp < n && stores[lp] <= 0) {
            lp++;
        }
        if (lp >= n) break;
        while(rp < n && rp < lp) {
            rp++;
        }
        if (rp >= n) break;

        // lp, rp same (both positive)
        while (rp < n && regpref[rp] - regpref[lp - 1] >= 0) {
            if (maxprofit < 2 * (regpref[rp] - regpref[lp - 1]) + (abspref[lp - 1]) + (abspref[n - 1] - abspref[rp])) {
                maxprofit = 2 * (regpref[rp] - regpref[lp - 1]) + (abspref[lp - 1]) + (abspref[n - 1] - abspref[rp]);
            }
            rp++;
        }
    }

    // separate case: no window at all
    if (maxprofit < abspref[n - 1]) {
        maxprofit = abspref[n - 1];
    }

    cout << maxprofit;
    return 0;
}