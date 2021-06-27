#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)cin >> v[i];
        int s = 0;
        for (int i = 0; i < n; i++)s += v[i];

        if (s % n) {
            cout << -1 << endl;
            continue;
        }

        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] <= s / n) {
                cout << n - i - 1 << endl;
                break;
            }
        }
    }
}
