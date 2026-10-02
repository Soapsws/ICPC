#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

long long process(long long h, const vector<long long>& a) {
    long long sum = 0;
    for (long long i = 0; i < a.size(); i++) {
        sum += h - a[i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int v = 0; v < t; v++) {

        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long lower = 0;
        long long upper = x + 1;

        long long solution = 0;

        while (lower <= upper) {
            long long med = (lower + upper) / 2;
            long long result = process(med, a);

            if (result == x) {
                solution = max(solution, med);
                break;
            } else if (result > x) {
                upper = med - 1;
            } else {
                solution = max(solution, med);
                lower = med + 1;
            }
        }

        cout << solution << '\n';
    }

    return 0;
}