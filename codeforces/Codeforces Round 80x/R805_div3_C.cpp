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

void solve() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    vector<pi> q(m);
    map<int, int> ck;
    map<int, vi> t;
    map<pi, int> r;
    for (int &x: v) cin >> x, ck[x]++;
    for (auto &[x, y]: q) cin >> x >> y, t[x].pb(y);

    for (int x: v) {
        if (--ck[x] == 0)ck.erase(x);
        if (t.count(x)) {
            for (int y: t[x]) if (ck.count(y)) r[{x, y}] = 1;
            t.erase(x);
        }
    }

    for(auto k: q) {
        cout << (r.count(k) ? "YES" : "NO") << endl;
    }
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
