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

    srand(time({}));
    for (int i = 0; i < t; i++) {
        for (int i = 0; i < 100; i++) {
            char guess;
            int r = rand();
            if (r > (RAND_MAX / 2)) {
                guess = 'T';
            } else {
                guess = 'F';
            }
            cout << guess;
            flush(cout);
            char ans;
            cin >> ans;
            char nextguess;
            if (ans == 'T') {
                nextguess = 'F';
            } else if (ans == 'F') {
                nextguess = 'T';
            } else {
                return 0;
            }
            cout << nextguess;
            flush(cout);
            cin >> ans;
        }
    }
    
    return 0;
}