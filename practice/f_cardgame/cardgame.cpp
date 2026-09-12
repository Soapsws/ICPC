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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    bool broken = 0;
    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        a[i] = card%n;
        for (int j = 1; j < m; j++) {
            cin >> card;
            card = card % n;
            if (card != a[i]) broken = 1;
            if (broken) break;
        }
        if (broken) break;
    }
    if (broken) cout << -1;

    vector<int> b(n);
    for (int i = 0; i < n; i++){
        b[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }


    return 0;
}