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
        // 0, k, k configuration

        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> frequencies(n);

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num < n) {
                frequencies[num]++;
            }
            a[i] = num;
        }

        if (frequencies[0] == 1) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';

        // Designate - A, B -> k, C -> 0

        vector<bool> afilled(n);

        for(int i = 0; i < n; i++) {
            if(a[i] >= n) {
                cout << 'C';
                continue;
            }
            if (frequencies[a[i]] >= 2) {
                if (!afilled[a[i]]) {
                    cout << 'A';
                    afilled[a[i]] = true;
                } else {
                    cout << 'B';
                }
            } else {
                cout << 'C';
            }
        }
        cout << '\n';
    }

    return 0;
}