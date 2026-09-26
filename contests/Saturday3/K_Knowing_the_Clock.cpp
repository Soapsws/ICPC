#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    cin >> h >> m;

    int past = h % 30;
    double ratio = (double)past / 30;

    double minratio = (double)m / 360;

    if (ratio == minratio) cout << "yes";
    else cout << "no";


    return 0;
}