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
        int n;
        cin >> n;

        int numzeros = 0;
        int numones = 0;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) numzeros++;
            else numones++;
        }

        bool isB = true;
        string winner = "";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a.size() - 1; j++) {
                if(a[j] != a[j+1]) {
                    if (isB) {
                        a[j] = max(a[j], a[j+1]);
                        numzeros--;
                        a.erase(a.begin() + j + 1);
                        break;
                    } else {
                        a[j] = min(a[j], a[j+1]);
                        numones--;
                        a.erase(a.begin() + j + 1);
                        break;
                    }
                }
            }
            if (numones == 0) {
                winner = "Elsie";
                break;
            } else if (numzeros == 0) {
                winner = "Bessie";
                break;
            }
            isB = !isB;
        }

        cout << winner << '\n';

    }


    return 0;
}