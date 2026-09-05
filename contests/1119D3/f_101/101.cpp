#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void execleft(vector<int>& a, int& lp, bool& bordl) {
    if (a[lp] == 0) {
        lp++;
    } else if (a[lp] == 1) {
        if (!bordl) {
            bordl = true;
            lp++;
        } else {
            lp++;
        }
    } else {
        if (!bordl) {
            a[lp] = 1;
            // cout << "left fixed at " << lp << '\n';
            bordl = true;
            lp++;
        } else {
            a[lp] = 0;
            // cout << "left zeroes at " << lp << '\n';
            lp++;
        }
    }
}

void execright(vector<int>& a, int& rp, bool& bordr) {
    if (a[rp] == 0) {
        rp--;
    } else if (a[rp] == 1) {
        if (!bordr) {
            bordr = true;
            rp--;
        } else {
            rp--;
        }
    } else {
        if (!bordr) {
            a[rp] = 1;
            // cout << "right fixed at " << rp << '\n';
            bordr = true;
            rp--;
        } else {
            // cout << "right zeroes at " << rp << '\n';
            a[rp] = 0;
            rp--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lp = 0;
        int rp = n - 1;

        bool bordl = (a[lp] == 1);
        bool bordr = (a[rp] == 1);

        if (n == 1 && a[0] == -1) {
            a[0] = 1;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << '\n';
            continue;
        }

        while (lp <= rp) {
            if (!bordl) {
                execleft(a, lp, bordl);
                execright(a, rp, bordr);
            } else {
                execright(a, rp, bordr);
                execleft(a, lp, bordl);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';

    }

    return 0;
}