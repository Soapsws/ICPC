#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int counter = 0;

    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        std::set<int> appear;
        while (curr != 0) {
            int digit = curr % 10;
            if (digit <= k) {
                appear.insert(digit);
            }
            curr /= 10;
        }
        if (appear.size() == k + 1) counter++;
    }


    cout << counter;


    return 0;
}