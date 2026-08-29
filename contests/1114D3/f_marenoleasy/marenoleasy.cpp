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
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}