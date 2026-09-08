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
        long long x;
        long long y;
        long long k;
        cin >> x >> y >> k;

        long long sum = 0;
        long long tick = 0;

        for (long long i = 0; i < k; i++) {
            if (2*(x+i) > (y+i)) {
                break;
            }
            long long res = (y + i) % (x + i);
            sum += res;
            tick++;
        }

        sum += (k - tick) * ((y + tick) % (x + tick));

        cout << sum << '\n';
    }


    return 0;
}