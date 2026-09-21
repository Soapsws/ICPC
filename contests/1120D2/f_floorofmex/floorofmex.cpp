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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> intervalTracker(n + 1, 0);
    for (int i = 0; i < n; i++) {
        // let a[i] = k;
        // this means the MEX of the floor of all elements of B / i + 1 = k;
        // therefore this rules out the interval [k * (i + 1), (k + 1) * (i + 1) - 1]
        // so, we let .first -> L, .second -> R and modify our interval array a(L)++, a(R+1)--;
        int L = a[i] * (i + 1);
int R = (a[i] + 1) * (i + 1) - 1;

if (L < n) {
    R = min(R, n - 1);

    intervalTracker[L]++;
    intervalTracker[R + 1]--;
}
    }

    int prefixOverIntervals = 0;
    vector<int> valids;

    for (int i = 0; i < n; i++) {
        prefixOverIntervals += intervalTracker[i];
        if (prefixOverIntervals <= 0) {
            valids.push_back(i);
        }
    }

    cout << valids.size() << '\n';
    for (int i : valids) {
        cout << i << " ";
    }
    cout << '\n';
}
    return 0;
}