#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;
        set<int> reps;

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            reps.insert(v - i);
        }

        int maxrun = 0;
        int curr = 0;
        int prev = -1;

        for (const auto& a : reps) {
            if (prev == -1) {
                prev = a;
                curr++;
                maxrun = max(maxrun, curr);
            } else {
                if (a == prev + 1) {
                    prev = a;
                    curr++;
                    maxrun = max(maxrun, curr);
                } else {
                    prev = a;
                    curr = 1;
                    maxrun = max(maxrun, curr);
                }
            }
        }

        cout << maxrun << '\n';
    }


    return 0;
}