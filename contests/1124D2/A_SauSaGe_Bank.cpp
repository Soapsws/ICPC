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
        int n, k;
        cin >> n >> k;

        int forces = k - 1;
        int left = n - forces;
        long long result = forces * 2 + (1LL << left);

        cout << result << '\n';
    }


    return 0;
}