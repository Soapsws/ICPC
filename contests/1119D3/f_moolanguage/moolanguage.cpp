#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int numFarms = n / k;

        int numPaid = 0;

        for (int i = 0; i < numFarms; i++) {
            bool forcebuy = true;
            int startIndex = i * k;
            for (int j = startIndex; j < startIndex + k; j++) {
                if (s[j] == '0') {
                    // cout << "buy at index " << j << '\n';
                    forcebuy = false;
                }
            }
            if (forcebuy) numPaid++;
        }

        cout << numPaid << '\n';
    }


    return 0;
}