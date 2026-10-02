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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int q;
    cin >> q;
    vector<int> b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        int sol = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << sol << '\n';
    }


    return 0;
}