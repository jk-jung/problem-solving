#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), diff(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
        if (diff[i] < 0)x -= diff[i];
        else y += diff[i];
    }

    if (x != y) {
        cout << -1 << endl;
        return;
    }

    vector<pi> r;
    for (int i = 0; i < n; i++) {
        while (diff[i] != 0) {
            for (int j = i + 1; j < n; j++) {
                if (diff[j] == 0)continue;
                if (diff[i] * diff[j] < 0) {
                    if (diff[i] < 0) {
                        diff[i]++;
                        diff[j]--;
                        r.pb({i, j});

                    } else {
                        diff[i]--;
                        diff[j]++;
                        r.pb({j, i});
                    }
                    j--;
                }
            }
        }
    }
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i].F + 1 << " " << r[i].S + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
