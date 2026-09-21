#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin >> a;
    string b;
    cin >> b;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        bool iscapital = false;
        bool done = false;
        if (c != tolower(c)) iscapital = true;
        for (int j = 0; j < 26; j++) {
            if (a[j] == c || a[j] == tolower(c)) {
                if (iscapital) cout << char(toupper(b[j]));
                else cout << b[j];
                done = true;
                break;
            }
        }
        if (done) continue;
        if ('0' <= c <= '9') {
            cout << c;
        }
    }

    return 0;
}