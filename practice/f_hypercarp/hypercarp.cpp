#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Types of swaps
    // 0 1 1 2 2 0
        // swap middle two -> saves (two) deletions

    // 0 1 1 3 2 0
        // swap 1 with 3 -> saves (one) deletion
    
    // 1 1 1 1
        // swaps are redundant and unnecessary

    // objective -> scan whether the most lucrative swap option exists
        // -> scan whether the second-highest lucrative swap option exists
            // else don't do swaps 

    // we only need max. one pass through for each scan -> O(N)

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool bestFound = false;

        // Scan for the most lucrative swap option
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == a[i-1]) {
                if (i + 2 < n && a[i+1] == a[i+2] && a[i] != a[i+1]) {
                    swap(a[i], a[i+1]);
                    bestFound = true;
                    break;
                }
            }
        }

        if (!bestFound) {
            for (int i = 1; i < n - 1; i++) {
                if (a[i] == a[i-1] && a[i] != a[i+1]) {
                    if (i + 2 < n) {
                        if (a[i] != a[i+2]) {
                            swap(a[i], a[i+1]);
                            bestFound = true;
                            break;
                        } else {
                            continue;
                        }
                    } 
                    swap(a[i], a[i+1]);
                    bestFound = true;
                    break;
                } else if(a[i] == a[i+1] && a[i] != a[i-1]) {
                    if (i - 2 >= 0) {
                        if (a[i] != a[i-2]) {
                            swap(a[i], a[i-1]);
                            bestFound = true;
                            break;
                        } else {
                            continue;
                        }
                    }
                    swap(a[i], a[i-1]);
                    bestFound = true;
                    break;
                }
            }
        }

        int deduction = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) deduction++;
        }

        cout << n - deduction << '\n';
    }

    return 0;
}