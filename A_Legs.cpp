#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // minimum -> chickens until divisible by 4 -> then all cows
    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {
        int n;
        cin >> n;

        int count = 0;
        while (n % 4 != 0) {
            count++;
            n -=2;
        }
        count += n / 4;
        cout << count << '\n';

    }



    return 0;
}