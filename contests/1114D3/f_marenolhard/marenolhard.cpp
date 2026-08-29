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
        string a;
        string b;
        cin >> a >> b;
    
        int oddtilesa = 0;
        int oddtilesb = 0;
        
        int eventilesa = 0;
        int eventilesb = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                if (a[i] == '1') {
                    oddtilesa++;
                }
                if (b[i] == '1') {
                    oddtilesb++;
                }
                
            } else {
                if (a[i] == '1') {
                    eventilesa++;
                }
                if (b[i] == '1') {
                    eventilesb++;
                }
            }

        }

        if (eventilesa == eventilesb && oddtilesa == oddtilesb) {
            // separate for evens and odds
            // even run
            int pa = 0;
            int pb = 0;

            long long evencounter = 0;

            for (int i = 0; i < eventilesa; i++) {
                while (pa < n && a[pa] != '1') pa +=2;
                while (pb < n && b[pb] != '1') pb +=2;

                if (pa >= n || pb >= n) break;

                // cout << pa << " " << pb << '\n';

                evencounter += abs(pa - pb) / 2;
                pa+=2;
                pb+=2;
            }

            // odd run
            pa = 1;
            pb = 1;

            long long oddcounter = 0;

            for (int i = 0; i < oddtilesa; i++) {
                while (pa < n && a[pa] != '1') pa +=2;
                while (pb < n && b[pb] != '1') pb +=2;

                if (pa >= n || pb >= n) break;

                // cout << pa << " " << pb << '\n';

                oddcounter += abs(pa - pb) / 2;
                pa +=2;
                pb +=2;
            }
            // cout << evencounter << " " << oddcounter;
            cout << evencounter + oddcounter << '\n';

        } else {
            cout << "-1" << endl;
        }

    }
    return 0;
}