#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {

        int n, m;
        cin >> n >> m;

        vector<string> words;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            words.push_back(s);
        }

        vector<string> abbreviations;
        for(int i = 0; i < m; i++) {
            string s;
            cin >> s;
            abbreviations.push_back(s);
        }

        cout << "Words: ";
        for (const auto& word : words) {
            cout << word << " ";
        }
        cout << '\n';
        cout << "Abbreviations: ";
        for (const auto& abbr : abbreviations) {
            cout << abbr << " ";
        }
        cout << '\n';



        std::set<char> letters;
        for (int i = 0; i < n; i++) {
            letters.insert(tolower(words[i][0]));
        }

        bool possible = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < abbreviations[i].length(); j++) {
                if (!letters.count(tolower(abbreviations[i][j]))) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}