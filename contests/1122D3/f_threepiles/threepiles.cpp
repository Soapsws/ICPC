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
        int a, b, c;
        cin >> a >> b >> c;

        if (a >= b) {
            cout << (a + c - b) << '\n';
            continue;
        } else {
            if (abs(a + c - b) > abs(a - b)) {
                cout << abs(a + c - b) << '\n';
            } else {
                cout << abs(a - b) << '\n';
            }
        }
    }


    return 0;
}