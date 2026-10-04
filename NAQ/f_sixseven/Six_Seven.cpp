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

    // Forever:
    // If there's a loop 123456789 -> what

    int t;
    cin >> t;
    for (int v = 0; v < t; v++) {
        string s;
        cin >> s;
        string sol = "";

        // Exist Case
        bool exist = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1] + 1) {
                exist = false;
                break;
            }
        }
        if (exist) {
            cout << s << '\n';
            continue;
        }
       
        bool firstperf = true;
        bool perf = true;
        for (int i = 0; i < s.length(); i++) {
            if ('9' - s[i] < s.length() - s[0] - i) {
                if (i == 0) firstperf = false;
                perf = false;
                break;
            }
        }

        // Perf Case - AKA no bottlenecks
        if (perf) {
            // cout << "perf";
            sol += s[0];
            for (int i = 1; i < s.length(); i++) {
                sol += (sol[i - 1] + 1);
            }
        } else if (firstperf) { // non-1 bottleneck
            // e.g. 1 2 4 4 5 6 7 8 9
            if (s.length() == 9) {
                cout << -1 << '\n';
                continue;
            }
            if ('9' - (s[0] + 1) < s.length() - 1) {
                sol += "1";
                for (int i = 1; i <= s.length(); i++) {
                    sol += (sol[i - 1] + 1);
                }
            } else { 
                sol += (s[0] + 1);
                for (int i = 1; i < s.length(); i++) {
                    sol += (sol[i - 1] + 1);
                }
            }
        } else { // 1 bottleneck
            // e.g. 2 2 3 4 5 6 7 8 9
            if (s.length() == 9) {
                cout << -1 << '\n';
                continue;
            }
            // good - you can always make a 1 2 3 4 ...
            sol += "1";
            for (int i = 1; i <= s.length(); i++) {
                sol += (sol[i - 1] + 1);
            }
        }

        cout << sol << '\n';
    }

    return 0;
}