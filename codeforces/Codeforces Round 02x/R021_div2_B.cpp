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


pi t(int a, int b) {
    if (b == 0)return mp(a ? 1 : 0, 0);
    if (b < 0)b = -b, a = -a;
    int g = gcd(a, b);
    return mp(a / g, b / g);
}

void solve() {
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    pi p = t(a, b), q = t(x, y);
    if (p == mp(0, 0) || q == mp(0, 0)) {
        if (p == mp(0, 0) && c)cout << 0;
        else if (q == mp(0, 0) && z)cout << 0;
        else cout << -1;
    } else if (p == q) {
        if (p.S == 0)
            cout << (a * z == c * x ? -1 : 0);
        else
            cout << (c * y == z * b ? -1 : 0);
    } else cout << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
