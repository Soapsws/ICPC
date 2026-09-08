#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

void resetBin(string& binx, string& biny) {
    // remove leading zeroes
    while (binx[0] == '0') {
        binx.erase(0, 1);
    }
    while (biny[0] == '0') {
        biny.erase(0, 1);
    }

    // pad with zeroes
    if (binx.length() > biny.length()) {
        for (int i = 0; i < binx.length() - biny.length(); i++) {
                biny = "0" + biny;
        }
    } else if (biny.length() > binx.length()) {
        for (int i = 0; i < biny.length() - binx.length(); i++) {
            binx = "0" + binx;
        }
    }

    std::reverse(binx.begin(), binx.end());
    std::reverse(biny.begin(), biny.end());

    // cout << binx << " " << biny << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int x, y;
        cin >> x >> y;

        string binx = std::bitset<32>(x).to_string();
        string biny = std::bitset<32>(y).to_string();

        resetBin(binx, biny);
        string sol = "";
        int count = 0;

        // digit
        int i = 0; 

        while (i < binx.length()) {
            if ((x ^ y) == (0 ^ (y+x))) {
                break;
            } // cout << "A";
            if ((static_cast<int>(binx[i]) ^ static_cast<int>(biny[i])) == 1) {
                // good
                sol = binx[i] + sol;
                // cout << "B";
                i++;
                continue;
            } else {
                if (binx[i] == '0') {
                    // good
                    sol = binx[i] + sol;
                    // cout << "C";
                } else {
                    // bad -> prop upwards
                    if (x - (1LL << i) < 0) {
                        y += x;
                        x = 0;
                        count += (y-x);
                        break;
                    }
                    x -= 1LL << i;
                    y += 1LL << i;
                    count += 1LL << i;

                    binx = std::bitset<32>(x).to_string();
                    biny = std::bitset<32>(y).to_string();
                    resetBin(binx, biny);
                    // cout << "D";
                }
            }
            i++;
        }

        cout << (x ^ y) << " " << count << '\n';
    }


    return 0;
}