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

    for(int l = 0; l < t; l++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lp = 0;
        int rp = n - 1;

        int fin = 0;

        for (int i = lp; i < n; i++) {
            if (a[i] == 1 || a[i] == -1) {
                a[i] = 1;
                fin = i;
                break;
            }
        }

        for (int i = rp; i > lp; i--) {
            if (a[i] == 1 || a[i] == -1) {
                a[i] = 1;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';


    }


    return 0;
}