#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // greatest pig
    // as much as possible

    int n;
    cin >> n;

    int mpig = 0;
    vector<int> nonpig;

    for (int i = 0; i < n; i++) {
        string s;
        int influence;
        cin >> s >> influence;
        if (s == "pig") {
            mpig = max(mpig, influence);
        } else {
            nonpig.push_back(influence);
        }
    }

    long long total = mpig;
    for (int i = 0; i < nonpig.size(); i++) {
        if (nonpig[i] < mpig) {
            total += nonpig[i];
        }
    }

    cout << total;
    return 0;
}