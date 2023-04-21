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

int x, y;

bool check(int x1, int y1, int x2, int y2, bool up) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int t = dy / dx;
    int ddx = x - x1;

    int r1 = y1 + ddx * t;
    if (up) return y >= r1;
    return y <= r1 ;
}

void solve() {
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    while (m--) {
        cin >> x >> y;

        bool ok = true;
        ok = ok && check(0, d, n - d, n, false);
        ok = ok && check(0, d, d, 0, true);
        ok = ok && check(d, 0, n, n - d, true);
        ok = ok && check(n - d, n, n, n - d, false);
        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
