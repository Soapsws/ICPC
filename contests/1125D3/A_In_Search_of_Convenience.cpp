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

    for (int v= 0; v < t; v++) {
        int x, y, R;
        cin >> x >> y >> R;

        bool solved = false;

        for (int i = -50; i < 50; i++){
            if (solved) break;
            for (int j = -50; j < 50; j++) {
                if (solved) break;
                if (R * R == (x-i)*(x-i)+(y-j)*(y-j)) {
                    cout << i << " " << j << '\n';
                    solved = true;
                }
            }
        }
    }

    return 0;
}