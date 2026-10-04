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

    long long n;
    cin >> n;

    long long sum = 0;
    long long MOD = 998244353;

    for (long long i = 1; i <= n; i++) {
        long long incr = ((i)*(i+1)/2) % MOD;
        sum += incr;
        sum %= MOD;
    }

    cout << sum;
    return 0;
}