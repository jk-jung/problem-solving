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

int n, m;
char a[105][105];

void run(vi &r) {
    for (int i = 0; i < r.size(); i += 2) a[r[i]][r[i + 1]] ^= 1;
}

vi off_first_row(int y, int x) {
    vi r;
    if (a[y][x] == 1)r.pb(y), r.pb(x);
    if (a[y][x + 1] == 1)r.pb(y), r.pb(x + 1);
    if (r.empty()) return r;

    for (int i = x; i <= x + 1 && r.size() < 6; i++)
        if (a[y + 1][i] == 1) r.pb(y + 1), r.pb(i);
    for (int i = x; i <= x + 1 && r.size() < 6; i++)
        if (a[y + 1][i] == 0) r.pb(y + 1), r.pb(i);
    run(r);
    return r;
}

vi off_first_col(int y, int x) {
    vi r;
    if (a[y][x] == 1)r.pb(y), r.pb(x);
    if (a[y + 1][x] == 1)r.pb(y + 1), r.pb(x);
    if (r.empty()) return r;

    for (int i = y; i <= y + 1 && r.size() < 6; i++)
        if (a[i][x + 1] == 1) r.pb(i), r.pb(x + 1);
    for (int i = y; i <= y + 1 && r.size() < 6; i++)
        if (a[i][x + 1] == 0) r.pb(i), r.pb(x + 1);
    run(r);
    return r;
}

void off_all(int y, int x, vector<vi> &rr) {
    vi a0, a1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            if (a[y + i][x + j] == 0) a0.pb(y + i), a0.pb(x + j);
            if (a[y + i][x + j] == 1) a1.pb(y + i), a1.pb(x + j);
        }
    vi r;

    // 4 -> 1 -> 2 -> 3 -> 0
    if (a1.empty()) return;
    else if (a1.size() == 2) {
        r = a1;
        r.pb(a0[0]), r.pb(a0[1]);
        r.pb(a0[2]), r.pb(a0[3]);
    } else if (a1.size() == 4) {
        r = a0;
        r.pb(a1[0]), r.pb(a1[1]);
    } else if (a1.size() == 6)r = a1;
    else r = a1, r.pop_back(), r.pop_back();

    run(r);
    rr.pb(r);
    return off_all(y, x, rr);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j], a[i][j] -= '0';

    vector<vi> r;
    for (int i = 0; i < n; i++) {
        if (i + 2 == n) {
            for (int j = 0; j + 1 < m; j += 2) {
                if (m % 2 && j + 3 == m)break;
                off_all(i, j, r);
            }
            if (m & 1) {
                r.pb(off_first_col(i, m - 3));
                off_all(i, m - 2, r);
            }
        } else {
            for (int j = 0; j + 1 < m; j += 2)
                r.pb(off_first_row(i, j));
            if (m & 1)
                r.pb(off_first_row(i, m - 2));
        }
    }
    vector<vi> tt;
    for (auto &x: r)if (!x.empty())tt.pb(x);
    r = tt;

    cout << r.size() << endl;
    for (auto &t: r) {
        for (int x: t)cout << x + 1 << " ";
        cout << endl;
    }
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
