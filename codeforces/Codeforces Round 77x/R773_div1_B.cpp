#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, pos;
vi v, t, r;
vector<pi> op;

void rev(int x) {
    r.pb(x * 2 + 2);
    for (int i = 0; i <= x; i++) {
        op.pb({x + pos + i, v[i]});
    }
    reverse(v.begin(), v.begin() + x + 1);
    pos += x * 2 + 2;
}

void solve() {
    r.clear();
    op.clear();
    pos = 0;

    cin >> n;
    v.resize(n);
    t.resize(n);

    map<int, int> ck;
    for (int &x: v)cin >> x, ck[x]++;

    int s = 0, e = n/2;
    for (auto[k, c]: ck) {
        if (c % 2) {
            cout << -1 << '\n';
            return;
        }
        while (c) {
            t[s++] = t[e++] = k;
            c -= 2;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == t[i])continue;

        int k = 0;
        for (;; k++)if (v[k] == t[i])break;

        if (k > 0)rev(k);
        rev(i);
    }
    r.pb(n);

    cout << op.size() << '\n';
    for (auto[a, b]: op)cout << a + 1 << " " << b << '\n';
    cout << r.size() << '\n';
    for (int x: r)cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
