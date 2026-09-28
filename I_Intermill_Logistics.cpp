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

    int n;
    double w;
    cin >> n >> w;

    vector<pair<double, double>> factories;
    for (int i = 0; i < n; i++) {
        double per_hour;
        double distance;
        cin >> per_hour >> distance;
        factories.push_back({per_hour, distance});
    }

    double low = 0;
    double high = pow(10, 10);
    double minimum = pow(10, 10) + 1;

    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2;
        // possibility check
        bool possible = true;
        double wheat = w;
        for (int i = 0; i < n; i++) {
            double max_processed = (mid - 2 * factories[i].second) * factories[i].first;
            if (max_processed > 0) wheat -= max_processed;
        }
        if (wheat > 0) possible = false;

        if (possible) {
            high = mid;
            minimum = min(minimum, mid);
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(10) << high;


    return 0;
}