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

vector<pi> v;

void go(int x, int y) {
    if (x > 0)v.pb(mp(0, x));
    else if (x < 0) v.pb(mp(-1, -x));
    if (y > 0)v.pb(mp(-2, y));
    else if (y < 0) v.pb(mp(-3, -y));
}

void solve() {
    int n;
    cin >> n;
    vector<pi> vv;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vv.pb(mp(x, y));
    }
    sort(vv.begin(), vv.end(), [](pi a, pi b) {
        return ab(a.F) + ab(a.S) < ab(b.F) + ab(b.S);
    });
    for (auto [x, y]: vv) {
        cin >> x >> y;
        go(x, y);
        v.pb(mp(2, 0));
        go(-x, -y);
        v.pb(mp(3, 0));
    }
    cout << v.size() << endl;
    for (auto x: v) {
        if (x.F == 0) cout << "1 " << x.S << " " << "R\n";
        else if (x.F == -1) cout << "1 " << x.S << " " << "L\n";
        else if (x.F == -2) cout << "1 " << x.S << " " << "U\n";
        else if (x.F == -3) cout << "1 " << x.S << " " << "D\n";
        else if (x.F == 2)cout << 2 << endl;
        else cout << 3 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
