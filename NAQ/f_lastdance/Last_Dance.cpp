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
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {
        int n, q, g;
        cin >> n >> q >> g;

        unordered_map<int, int> recgenre;
        unordered_map<int, int> numpeople;

        for (int i = 0; i < q; i++) {
            char comm;
            cin >> comm;
            if (comm == 'P') {
                int s, a;
                cin >> s >> a;
                for (int i = 0; i < a; i++) {
                    int per;
                    cin >> per;
                    numpeople[recgenre[per]] = max(0, numpeople[recgenre[per]] - 1);
                    recgenre[per] = s;
                    numpeople[s]++;
                }
            } else {
                int s;
                cin >> s;
                cout << numpeople[s] << '\n';
            }   
        }
    }

    return 0;
}