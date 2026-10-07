#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <numeric>
#include <climits>
#include <utility>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long total = (k == 0 ? n : 0);

    // Construct Groups

    // (1) find all nodes with degree 1
    vector<int> degree(n);
    queue<int> peeler;
    vector<bool> removed(n, false);

    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1) peeler.push(i);
    }

    // (2) find loop

    while (!peeler.empty()) {
        int f = peeler.front();
        peeler.pop();
        if (removed[f]) continue;
        removed[f] = true;

        for (int v: adj[f]) {
            if (removed[v]) continue;
            degree[v]--;
            if (degree[v] == 1) {
                peeler.push(v);
            }
        }
    }

    // (3) iterate outwards in groups
    
    // Use Branch IDs

    vector<int> cyclers;
    for (int i = 0; i < n; i++) {
        if (!removed[i]) cyclers.push_back(i);
    }

    vector<int> branchroots(n, -1);
    for (int i : cyclers) {
        branchroots[i] = i;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (branchroots[v] != -1 || !removed[v]) continue;
                branchroots[v] = i;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (values[i] - values[j] == k) {
                if (branchroots[j] == branchroots[i]) {
                    total += 1;
                } else {
                    total += 2;
                }
            }
        }
    }

    cout << total;

    return 0;
}