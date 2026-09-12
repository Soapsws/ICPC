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

    // keeping a positive is always a net positive
    // when to reset to 0?

    vector<int> pos_values;
    for (int i = 0; i < n; i++) {
        if (stores[i] > 0) pos_values.push_back(i);
    }

    for (int i : pos_values) {
        if (i == 0 || stores[i] <= 0) continue;
        for (int j = i; j < n; j++) {
            if (stores[j] <= 0) continue;
            // start at i, end at j
            if (maxprofit < 2 * (regpref[j] - regpref[i - 1]) + (abspref[i - 1]) + (abspref[n - 1] - abspref[j])) {
                maxprofit = 2 * (regpref[j] - regpref[i - 1]) + (abspref[i - 1]) + (abspref[n - 1] - abspref[j]);
            }
        }
    }

    // separate case: no window at all
    if (maxprofit < abspref[n - 1]) {
        maxprofit = abspref[n - 1];
    }

    cout << maxprofit;
    return 0;
}