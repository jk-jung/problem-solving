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
        vector<int> v(n), v2;
        for (int i = 0; i < n; i++)cin >> v[i];
        v2 = v;
        sort(v2.begin(), v2.end());
        int s = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == v2[0]) s = i;
            if (v[i] == v2[n - 1]) e = i;
        }
        int l = min(s, e);
        int r = max(s, e);

        cout << min(
                min(r + 1, n - l),
                l + 1 + n - r
        ) << endl;
    }
}
