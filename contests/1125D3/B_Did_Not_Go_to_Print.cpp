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
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        stack<int> sta;
        vector<int> extras;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '1') {
                // scan - place item
                sta.push(i);
            }
            else if (c == '2') {
                // print from memory
                if (sta.empty()) {
                    // print current doc - nothing stored
                    continue;
                } else {
                    extras.push_back(i);
                    sta.pop();
                }
            } else {
                // quick print - nothing stored
                continue;
            }
        }

        cout << (sta.size()+extras.size()) << '\n';
        vector<int> rem;
        while (!sta.empty()) {
            rem.push_back(sta.top());
            sta.pop();
        }
        for (int i : extras) {
            rem.push_back(i);
        }
        sort(rem.begin(), rem.end());
        for (int i : rem) {
            cout << (i + 1) << " ";
        }
        cout << '\n';
    }

    return 0;
}