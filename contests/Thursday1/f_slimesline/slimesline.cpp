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

    vector<int> slimes;
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        slimes.push_back(pos);
    }

    sort(slimes.begin(), slimes.end());

    int result = ceil(((double)slimes[n - 1] - slimes[0]) / 2);
    cout << result << '\n';
}

    return 0;

}