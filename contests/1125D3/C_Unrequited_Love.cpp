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
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> loves;
        for (int i = 0; i < 60009; i++) {
            vector<int> g;
            loves.push_back(g);
        }

        // cout << loves.size() << '\n';

        // Started at (i)
        for (int i = 0; i < n - 4; i++) {
            int love = a[i] + a[i + 2] - a[i + 4];
            // if negative normalize (could be buggy)
            loves[love+30000].push_back(i);
        }

        int total = 0;

        for (vector<int> compartment: loves) {
            if (compartment.size() < 2) continue;
            if (compartment.size() > 1) {
                // Now, we perform our legality check
                // Each element can have a maximum of two banned fellows, namely the ones that start with 
                // a + 2 or a + 4. 
                // we keep track of these using a decrement counter spanning from 0 to 2.
                // finally when performing our combinatoric calculation we make sure to reduce the factor by dec.
                // NOTE that each compartment should be sorted already
                // should still be O(n)
                for (int i = 0; i < compartment.size(); i++) {
                    int dec = 0;
                    int curr = compartment[i];
                    // can optimize for hard-checks because can only be two possible
                    // bool contains1 = binary_search(compartment.begin(), compartment.end(), curr + 2);
                    // bool contains2 = binary_search(compartment.begin(), compartment.end(), curr + 4);
                    // if (contains1) dec++;
                    // if (contains2) dec++;

                    bool contains1 = false;
                    bool contains2 = false;
                    for (int j = 1; j <= 4; j++) {
                        if (i + j >= compartment.size()) continue;
                        if (compartment[i + j] == curr + 2) contains1 = true;
                        if (compartment[i + j] == curr + 4) contains2 = true;
                    }
                    if (contains1) dec++;
                    if (contains2) dec++;
                    
                    // number of possible
                    // could it be negative? (possible bug) - don't think so
                    total += (compartment.size() - 1 - i - dec);
                }
            }
        }
        cout << total << '\n';
    }

    return 0;
}