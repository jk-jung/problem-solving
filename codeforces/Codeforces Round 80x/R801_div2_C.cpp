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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> v(n, vi(m)), a(n, vi(m, 1 << 30)), b(n, vi(m, -(1 << 30)));
    for (auto &x: v)for (auto &y: x)cin >> y;

    int t = n + m - 1;
    if (t % 2) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) a[i][j] = b[i][j] = v[i][j];
            else if (i == 0) {
                a[i][j] = a[i][j - 1] + v[i][j];
                b[i][j] = b[i][j - 1] + v[i][j];
            } else if (j == 0) {
                a[i][j] = a[i - 1][j] + v[i][j];
                b[i][j] = b[i - 1][j] + v[i][j];
            } else {
                a[i][j] = min(a[i - 1][j], a[i][j - 1]) + v[i][j];
                b[i][j] = max(b[i - 1][j], b[i][j - 1]) + v[i][j];
            }
        }
    }

    cout << (a[n - 1][m - 1] <= 0 && b[n - 1][m - 1] >= 0 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
