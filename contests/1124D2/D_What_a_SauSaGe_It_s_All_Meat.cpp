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

    for (int v = 0; v < t; v++) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int counter = 0;
        for (int i = 1; i <= n; i++) {
            if (__builtin_popcount(a[i]) % 2 == 0) counter++;
        }
        cout << counter << " ";

        for (int i = 0; i < q; i++) {
            int p, x;
            cin >> p >> x;
            if (__builtin_popcount(a[p]) % 2 == 0) {
                if (__builtin_popcount(x) % 2 != 0) {
                    counter--;
                }
            } else {
                if (__builtin_popcount(x) % 2 == 0) {
                    counter++;
                }
            }         
            a[p] = x;
            cout << counter << " ";  
        }
        cout << '\n';
    }

    return 0;
}