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

int rr = 0;

int f(int x, int cnt) {
    rr += cnt;
    for (ll i = 1, b = 10;; i++, b *= 10) {
        if (b > x)return i;
    }
}

map<int, int> calc(map<int, int> &a, int limit) {
    map<int, int> r;
    for (auto [x, y]: a) {
        int z = x < limit ? x : f(x, y);
        r[z] += y;
    }
    return r;
}

void process(map<int, int> &a, map<int, int> &b, map<int, int> &c, map<int, int> &d, int limit) {
    map<int, int> ta = calc(a, limit);
    map<int, int> tb = calc(b, limit);

    for (auto [x, y]: ta) {
        int cnt = max(0, y - (tb.count(x) ? tb[x] : 0));
        if (cnt) c[x] = cnt;
    }
    for (auto [x, y]: tb) {
        int cnt = max(0, y - (ta.count(x) ? ta[x] : 0));
        if (cnt) d[x] = cnt;
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, int> ma, mb, mc, md;
    for (int &x: a)cin >> x, ma[x]++;
    for (int &x: b)cin >> x, mb[x]++;

    rr = 0;
    for (int i: {1 << 30, 10, 2, 2}) {
        process(ma, mb, mc, md, i);
        ma = mc;
        mb = md;
        mc.clear();
        md.clear();
    }
    cout << rr << endl;
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
