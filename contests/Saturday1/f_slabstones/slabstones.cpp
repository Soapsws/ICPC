#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // total space L, R

    int n, m, d, x;
    cin >> n >> m >> d >> x;

    vector<pair<int, int>> slabs;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        slabs.push_back(make_pair(a, b));
    }

    // n slabs

    // space to the left and right of each slab
    vector<int> spaceleft(n);
    vector<int> spaceright(n);
    vector<int> gaps(n + 1); // includes edges

    spaceleft[0] = slabs[0].first;


    for (int i = 1; i < n; i++) {
        spaceleft[i] = spaceleft[i-1] + (slabs[i].first - slabs[i-1].second) - d;
    }

    spaceright[n - 1] = m - slabs[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        spaceright[i] = spaceright[i+1] + (slabs[i+1].first - slabs[i].second) - d;
    }

    gaps[0] = slabs[0].first;
    gaps[n] = m - slabs[n - 1].second;

    for (int i = 1; i < n; i++) {
        gaps[i] = slabs[i].first - slabs[i-1].second;
    }


    int mincost = -1;
    for (int i = 0; i <= n; i++) {
        if (gaps[i] >= x + 2 * d) {
            cout << "free" << '\n';
            mincost = 0;
            break;
        } else {
            int sleft, sright;
            if (i == 0) {
                sleft = 0;
                sright = spaceright[i];

                if (gaps[i] + sright >= x + d) {
                    int counter = 0;
                    int multiplier = 1;
                    int goal = d - gaps[i];
                    int covered = 0;

                    while (covered < goal) {
                        // separate case for end?
                        int dist;
                        if (i + multiplier >= n) dist = slabs[n-1].second;
                        else dist = min(goal - covered, slabs[i+multiplier].first - slabs[i+multiplier-1].second);
                        covered += dist;
                        counter += multiplier * dist;
                        multiplier++;
                    }
                    if (mincost == -1) mincost = counter;
                    else mincost = min(mincost, counter);
                }

            } else if (i == n) {
                sright = 0;
                sleft = spaceleft[i - 1];

                if (gaps[i] + sleft >= x + d) {
                    int counter = 0;
                    int multiplier = 1;
                    int goal = d - gaps[i];
                    int covered = 0;

                    while (covered < goal) {
                        // separate case for end?
                        int dist;
                        if (i - multiplier - 1 < 0) dist = slabs[0].first;
                        else dist = min(goal - covered, slabs[i - multiplier].first - slabs[i - multiplier - 1].second);
                        covered += dist;
                        counter += multiplier * dist;
                        multiplier++;
                    }

                    if (mincost == -1) mincost = counter;
                    else mincost = min(mincost, counter);
                }

            } else {
                sleft = spaceleft[i - 1];
                sright = spaceright[i];

                if (gaps[i] + sleft + sright >= x + 2 * d) {
                    
                }
            }
        }
    }

    cout << mincost;
    return 0;
}