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

        int x, y, z;
        cin >> x >> y >> z;

        cout << n - min(x, min(y, z)) << '\n';
    }


    return 0;
}