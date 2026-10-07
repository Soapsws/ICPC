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

        long long n, k;
        cin >> n >> k;

        vector<vector<long long>> labs;
        for (int i = 0; i < n; i++) {
            vector<long long> curr;
            long long a, b, c;
            cin >> a >> b >> c;
            curr.push_back(a);
            curr.push_back(b);
            curr.push_back(c);
            labs.push_back(curr);
        }

        // custom sorter i don't know if this will work
        std::sort(labs.begin(), labs.end(), [](const vector<long long>&a, const vector<long long>& b) {
            long long suma = a[0] + a[1] + a[2];
            long long sumb = b[0] + b[1] + b[2];
            return suma >= sumb;
        } );

        long long best = 0;
        long long lp = 0;
        // chec this later
        long long rp = numeric_limits<long long>::max() / 2;
        while (lp <= rp) {
           long long med = (lp + rp / 2); // this is our tentative S value
           // feasible
           bool possible = false;
           long long kcopy = k;

            for (long long i = 0; i < n; i++) {
                // fix labs until we reach a good threshold
                // bug - there's one at the end with length zero???
                if (labs[i].size() < 2) break;
                long long a = labs[i][0];
                long long b = labs[i][1];
                long long c = labs[i][2];
                long long currsum = a + b + c;
                if (currsum >= med) {
                    possible = true;
                    break;
                }
                if (a > b || a > c || b > c) {
                    // pumpable
                    long long diff = med - currsum;
                    if (diff > kcopy) {
                        possible = false;
                        break;
                        // can't pump
                    }
                    kcopy -= diff;
                } else {
                    // not possible, it's not above S right now and we can never make it
                    possible = false;
                    break;
                }
            }

           if (possible) {
            best = max(best, med);
            lp = med + 1;
           } else {
            rp = med - 1;
           }
        }

        cout << best << '\n';
    }   


    return 0;
}