#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <numeric>
#include <climits>
#include <utility>

using namespace std;

bool checkdigits(int n) {
    int last = n % 10;
    n /= 10;
    while (n != 0) {
        int curr = n % 10;
        if (last - curr != 1) return false;
        last = curr;
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int v = 0; v < t; v++) {
        int n;
        cin >> n;

        while (!checkdigits(n)) {
            n++;
        }
        cout << n << '\n';
    }

    return 0;
}