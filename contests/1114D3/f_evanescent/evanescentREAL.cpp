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

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int condensations = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) condensations++;

            // a a b b b c -> condensations = 3
        }

        int maxcond = 0;

        for (int i = 1; i < n - 1; i++) {
            int currcond = 0;
            // cases:
            // aaa
            // aab
            // aba
            // baa
            // abc


            if (s[i] == s[i-1] || s[i] == s[i+1]) currcond--; 
            else if (s[i-1] == s[i+1]) currcond+=2;
            else currcond++;
            maxcond = max(maxcond, currcond);
        }

        cout << s.length() - condensations - maxcond << "\n";
    }


    return 0;
}