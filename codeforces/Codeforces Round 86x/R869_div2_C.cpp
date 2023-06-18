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

int f(pi a) {
    return min(2, a.S - a.F + 1);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n), ss;
    for (int &x: v)cin >> x;
    vector<pi> t;
    for (int i = 0; i < n;) {
        int j = i;
        while (j + 1 < n && v[j] >= v[j + 1])j++;
        if (j == n)j--;
        t.pb({i, j});
        i = j + 1;
    }
    ss.pb(0);
    for (auto x: t) ss.pb(ss.back() + f(x));

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int s = lower_bound(t.begin(), t.end(), mp(a, a)) - t.begin();
        int e = lower_bound(t.begin(), t.end(), mp(b + 1, b + 1)) - t.begin();
        if (s == t.size() || t[s].F > a)s--;
        e--;

        int r = f(mp(a, min(b, t[s].S)));
        if (s != e)r += f(mp(max(s, t[e].F), b));
        if (s + 1 <= e)
            r += ss[e] - ss[s + 1];

        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
