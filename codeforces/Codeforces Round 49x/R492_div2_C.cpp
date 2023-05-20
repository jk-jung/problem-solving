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

int n, m, k = 0;
int a[4][55];

vector<tuple<int, int, int>> r;

void check() {
    for (int j = 0; j < n; j++) {
        if (a[0][j] == a[1][j] && a[1][j]) {
            r.pb({a[0][j], 1, j + 1});
            a[1][j] = 0;
            k++;
        }
        if (a[2][j] == a[3][j] && a[3][j]) {
            r.pb({a[2][j], 4, j + 1});
            a[2][j] = 0;
            k++;
        }
    }
}

bool move() {
    for (int i = 0; i < n; i++) {
        if (a[1][i] == 0)continue;
        int &x = a[1][i];
        if (i == 0) {
            if (a[2][i] == 0) {
                r.pb({x, 3, i + 1});
                swap(x, a[2][i]);
                return true;
            }
        } else {
            if (a[1][i - 1] == 0) {
                r.pb({x, 2, i});
                swap(x, a[1][i - 1]);
                return true;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[2][i] == 0)continue;
        int &x = a[2][i];
        if (i == n - 1) {
            if (a[1][n - 1] == 0) {
                r.pb({x, 2, i + 1});
                swap(x, a[1][n - 1]);
                return true;
            }
        } else {
            if (a[2][i + 1] == 0) {
                r.pb({x, 3, i + 2});
                swap(x, a[2][i + 1]);
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < 4; i++)for (int j = 0; j < n; j++)cin >> a[i][j];

    while (true) {
        check();
        if (k == m)break;
        if (!move()) {
            cout << "-1\n";
            return;
        }
    }
    cout << r.size() << endl;
    for (auto [x, y, z]: r) cout << x << " " << y << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
