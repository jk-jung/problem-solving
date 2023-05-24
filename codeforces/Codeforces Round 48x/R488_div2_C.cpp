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
    vi a(4), b(4), c(4), d(4);
    for (int i = 0; i < 4; i++)cin >> a[i] >> b[i];
    for (int i = 0; i < 4; i++)cin >> c[i] >> d[i];

    int sx = *min_element(a.begin(), a.end());
    int ex = *max_element(a.begin(), a.end());
    int sy = *min_element(b.begin(), b.end());
    int ey = *max_element(b.begin(), b.end());

    int sx2 = *min_element(c.begin(), c.end());
    int ex2 = *max_element(c.begin(), c.end());
    int sy2 = *min_element(d.begin(), d.end());
    int ey2 = *max_element(d.begin(), d.end());

    int xx = (sx2 + ex2) / 2;
    int yy = (sy2 + ey2) / 2;
    int dd = (ex2 - sx2) / 2;

    for (int y = sy; y <= ey; y++) {
        for (int x = sx; x <= ex; x++) {
            if (ab(x - xx) + ab(y - yy) <= dd) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
