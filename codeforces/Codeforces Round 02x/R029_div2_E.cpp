#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int n, m;
int d[555][555];
pi f[555][555];

vi v[555];

void print(vi &v) {
    reverse(v.begin(), v.end());
    for (int &x: v)cout << x << " ";
    cout << endl;
}

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    queue<pi> q;
    q.push(mp(1, n));
    d[1][n] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int val = d[x][y];
        if (x == n && y == 1) {
            cout << val - 1 << endl;
            vi a, b;
            a.pb(x), b.pb(y);
            while (x != 1 || y != n) {
                pi k = f[x][y];
                x = k.F;
                y = k.S;
                a.pb(x), b.pb(y);
            }
            print(a);
            print(b);
            return;
        }

        for (int a: v[x]) {
            for (int b: v[y]) {
                if (a == b || d[a][b])continue;
                d[a][b] = val + 1;
                q.push(mp(a, b));
                f[a][b] = mp(x, y);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
