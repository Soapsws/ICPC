#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Possible openings

    // 0 0 1 1 ...
    // 0 1 1 0 0 1 1 ...
    // 1 0 0 1 1 ...
    // 1 1 0 0 1 1 ...

    // 4 -> locked into pattern

    // 0 ? 1 1

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;

        string s;
        cin >> s;
 
        bool possible = true;

        // by parity each half-chain can only be 0101... or 1010...

        int multiplier = 1;

        for (int parity = 0; parity < 2; parity++) {
            int firstDefinite = -1;
            for (int i = parity; i < n; i += 2) {
                if (s[i] != '?') {
                    firstDefinite = i;
                    break;
                }
            }

            if (firstDefinite == -1) {
                multiplier *= 2;
            } else {
                char assumed = s[firstDefinite];
                for (int j = firstDefinite; j < n; j += 2) {
                    if (s[j] == assumed || s[j] == '?') {
                        if (assumed == '1') {
                            assumed = '0';
                        } else assumed = '1';
                    } else {
                        multiplier *= 0;
                    }

                }
            }
        }

        cout << multiplier << '\n';

    }


    return 0;
}