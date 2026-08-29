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

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >>c;
   
        int most, middle, least;
        most = max({a, b, c});
        least = min({a, b, c});
        middle = a + b + c - most - least;

        cout << min(most - middle, middle-least) << '\n';

    }
    return 0;
}