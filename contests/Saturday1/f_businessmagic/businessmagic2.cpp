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

    long long abs_sum = 0;
    for (long long i : stores) {
        abs_sum += abs(i);
    }

    long long maxprofit = 0;

    vector<long long> kadane(n);
    kadane[0] = 2 * stores[0] - abs(stores[0]);

    for (int i = 1; i < n; i++) {
        long long ri = 2 * stores[i] - abs(stores[i]);
        if (ri > kadane[i - 1] + ri) {
            kadane[i] = ri;
        } else {
            kadane[i] = kadane[i-1] + ri;
        }
    }

    long long a = 0;
    maxprofit = max(a , *max_element(kadane.begin(), kadane.end())) + abs_sum;

    cout << maxprofit;
    return 0;
}