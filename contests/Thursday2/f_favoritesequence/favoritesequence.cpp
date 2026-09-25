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
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            if (l == r) {
                cout << b[l];
                break;
            }
            cout << b[l] << " " << b[r] << " ";
            l++;
            r--;
        }  
        cout << '\n';
    }

    return 0;
}