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


int d(pi a, pi b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

void f(vector<pi> v, int idx, int dx, int dy, string s) {
    v[idx].F += dx;
    v[idx].S += dy;

    vector<ll> t(3);
    t[0] = d(v[0], v[1]);
    t[1] = d(v[0], v[2]);
    t[2] = d(v[1], v[2]);
    sort(t.begin(), t.end());
    if (t[2] == t[0] + t[1] && t[0] > 0) {
        cout << s << endl;
        exit(0);
    }
}

void solve() {
//    "0 0 1 0 4 1"
    vector<pi> v(3);
    for (pi &x: v)cin >> x.F >> x.S;
    f(v, 0, 0, 0, "RIGHT");
    for (int i = 0; i < 3; i++) {
        f(v, i, 1, 0, "ALMOST");
        f(v, i, -1, 0, "ALMOST");
        f(v, i, 0, 1, "ALMOST");
        f(v, i, 0, -1, "ALMOST");
    }
    cout << "NEITHER\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
