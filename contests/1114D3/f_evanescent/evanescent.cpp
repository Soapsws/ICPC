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

        vector<int> max_with_delete(26, 0);
        vector<int> max_wo_delete(26, 0);

        // Without Delete

        for (int i = 0; i < 26; i++) {
            int currl = 0;
            int maxl = 0;

            int index = 0;
            while (index < n) {
                while (index < n && s[index] != 'a' + i) {
                    index++;
                }
                if (index >= n) break;

                while (index < n && s[index] == 'a' + i) {
                    currl++;
                    maxl = max(maxl, currl);
                    index++;
                }

                currl = 0;
            }

            max_wo_delete[i] = maxl;
        }

        vector<int> optimalends(26, 0);

        // With Delete 

        for(int i = 0; i < 26; i++) {
            int currl = 0;
            int maxl = 0;

            int optimalend = 0;

            int index = 0;
            while (index < n) {
                while (index < n && s[index] != 'a' + i) {
                    index++;
                }
                if (index >= n) break;

                int tag = 0;
                bool interrupt = false;
                while (index < n && !interrupt) {
                    if (s[index] == 'a' + i) {
                        currl++;
                        maxl = max(maxl, currl);
                        optimalend = index;
                        optimalends[i] = optimalend;
                    } else {
                        if (tag == 0) {
                            tag = 1;
                        }
                        else {
                            interrupt = true;
                            currl = 0;
                        }
                    }
                    index++;
                }

            }

            max_with_delete[i] = maxl;
        }

        int chosenindex = 0;
        int maxindex = 0;
        for (int i = 0; i < 26; i++) {
            if (max_with_delete[i] > maxindex) {
                maxindex = max_with_delete[i];
                chosenindex = i;
            }
        }

        int deletedindex = 0;
        if (optimalends[chosenindex] == n - 1) deletedindex--;
        for(int i = optimalends[chosenindex]; i > 0; i--) {
            if (s[i] != 'a' + chosenindex) {
                deletedindex = i;
                break;
            }
        }

        char deletedchar = s[deletedindex];
        int currl = 0;
        int newmaxworeplace = 0;

        int index = 0;
        while (index < n) {
            while (index < n && s[index] != deletedchar) {
                index++;
            }
            if (index >= n) break;

            while (index < n && s[index] == deletedchar) {
                if (index != deletedindex) currl++;
                newmaxworeplace = max(newmaxworeplace, currl);
                index++;
            }

            currl = 0;
        }
        
        
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (i == chosenindex) sum += max_with_delete[i];
            else if(i == deletedchar - 'a') sum += newmaxworeplace;
            else sum += max_wo_delete[i];
        }

        int num_compressed = 0;
        for(int i = 0; i < 26; i++) {
            if (i == chosenindex) {
                if (max_with_delete[i] > 0) num_compressed++;
            } 
            else if (i == deletedchar - 'a') {
                if (newmaxworeplace > 0) num_compressed++;
            } else {
                if (max_wo_delete[i] > 0) num_compressed++;
            }
        }

        int sol = s.length() - sum + num_compressed - 1;
        if (num_compressed == 1) sol += 1;
        cout << "sum: " << sum << " num_compressed: " << num_compressed << " sol: ";
        cout << sol << "\n";
    }

    return 0;
}