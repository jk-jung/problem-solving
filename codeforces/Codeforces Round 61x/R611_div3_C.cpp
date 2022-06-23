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
    int n;
    cin >> n;
    vi v(n), t(n + 1);
    for (int &x: v)cin >> x, t[x] = 1;

    vi a, b, c, d;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0 && t[i + 1] == 0) a.pb(i + 1), c.pb(i), t[i + 1] = 1;
        else if (t[i + 1] == 0)b.pb(i + 1);
        else if (v[i] == 0) d.pb(i);
    }

    if (b.size()) {
        a.pb(b.back());
        b.pop_back();
        c.pb(d.back());
        d.pop_back();
    }
    for (int i = 0; i < a.size(); i++) {
        int x = c[i], y = a[(i + 1) % a.size()];
        v[x] = y;
    }
    for (int i = 0; i < b.size(); i++)v[d[i]] = b[i];
    for (int x: v)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
