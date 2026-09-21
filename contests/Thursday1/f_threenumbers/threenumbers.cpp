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

    for (int l = 0; l < t; l++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> nums;
        nums.push_back(a);
        nums.push_back(b);
        nums.push_back(c);

        sort(nums.begin(), nums.end());

        int minrange = nums[2] - nums[0];
        bool exit = false;
        while (!exit) {
            int temp = nums[0] + nums[1];
            if (max(temp, nums[2]) - nums[0] < minrange) {
                minrange = max(temp, nums[2]) - nums[0];
                if (nums[2] < temp) {
                    nums[0] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = temp;
                } else {
                    nums[0] = nums[1];
                    nums[1] = temp;
                }
            } else {
                exit = true;
            }
        }

        cout << minrange << '\n';

    }


    return 0;
}