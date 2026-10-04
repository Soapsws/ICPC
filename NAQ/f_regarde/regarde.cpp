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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int v = 0; v < t; v++) {
        int n;
        cin >> n;
        string s = "s";
        for (int i = 0; i < n + 1; i++) {
            s += "h";
        }
        cout << s << '\n';
    }

    return 0;
}