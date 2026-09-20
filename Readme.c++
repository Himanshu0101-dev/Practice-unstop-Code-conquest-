#include <bits/stdc++.h>
using namespace std;

bool canScoreTarget(vector<int>& arr) {
    int n = arr.size();
    int target = n - 1;

    int runs = 0;   // total runs scored so far
    int pos = 0;    // current ball index

    while (pos < n && runs < target) {
        if (arr[pos] == 0) return false;  // stuck, cannot progress

        // choose runs to score on this ball
        int step = min(arr[pos], target - runs);
        runs += step;
        pos += step;
    }

    // success if exactly target runs scored and landed at last ball
    return (runs == target && pos == n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << (canScoreTarget(arr) ? "true" : "false") << "\n";
    return 0;
}
