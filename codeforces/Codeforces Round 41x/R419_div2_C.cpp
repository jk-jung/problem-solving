#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int a[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pi> r;
    if (n < m) {
        while (1) {
            bool ck = false;
            for (int i = 0; i < n; i++) {
                int cnt = 1 << 30;
                for (int j = 0; j < m; j++)cnt = min(cnt, a[i][j]);
                if (cnt >= 1) {
                    ck = true;
                    for (int j = 0; j < m; j++)a[i][j] -= cnt;
                    while (cnt--)r.pb({0, i});
                }
            }
            for (int i = 0; i < m; i++) {
                int cnt = 1 << 30;
                for (int j = 0; j < n; j++)cnt = min(cnt, a[j][i]);
                if (cnt >= 1) {
                    ck = true;
                    for (int j = 0; j < n; j++)a[j][i] -= cnt;
                    while (cnt--)r.pb({1, i});
                }
            }

            if (!ck)break;
        }
    } else {
        while (1) {
            bool ck = false;
            for (int i = 0; i < m; i++) {
                int cnt = 1 << 30;
                for (int j = 0; j < n; j++)cnt = min(cnt, a[j][i]);
                if (cnt >= 1) {
                    ck = true;
                    for (int j = 0; j < n; j++)a[j][i] -= cnt;
                    while (cnt--)r.pb({1, i});
                }
            }
            for (int i = 0; i < n; i++) {
                int cnt = 1 << 30;
                for (int j = 0; j < m; j++)cnt = min(cnt, a[i][j]);
                if (cnt >= 1) {
                    ck = true;
                    for (int j = 0; j < m; j++)a[i][j] -= cnt;
                    while (cnt--)r.pb({0, i});
                }
            }
            if (!ck)break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << r.size() << endl;
    for (auto [x, y]: r) {
        cout << (x == 0 ? "row " : "col ") << y + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
