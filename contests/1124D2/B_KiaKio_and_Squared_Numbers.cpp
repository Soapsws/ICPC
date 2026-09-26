#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int decompose(int i) {
    long long num = 0;
    while (i > 0) {
        long long digit = i % 10;
        num += digit * digit;
        i /= 10;
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // O(N^2) works?

    for (int v = 0; v < t; v++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int counter = 0;

        int runs = 500;
        for (int i = 0; i < runs; i++) {
            for (int j = 0; j < n; j++) {
                a[j] = decompose(a[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) counter++;
            }
        }

        cout << counter << '\n';
    }


    return 0;
}