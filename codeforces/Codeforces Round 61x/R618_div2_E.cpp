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

vector<double> r, v;

double val(pi a) {
    double s = v[a.S];
    if (a.F > 0)s -= v[a.F - 1];
    return s / (a.S - a.F + 1);
}

bool can(pi a, pi b) {
    return val(b) < val(a);
}

void solve() {
    int n;
    cin >> n;
    v.resize(n), r.resize(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[i] = x;
        if (i)v[i] += v[i - 1];
    }
    vector<pi> seg;
    for (int i = 0; i < n; i++) {
        pi s = {i, i};
        while (!seg.empty() && can(seg.back(), s)) {
            s.F = seg.back().F;
            seg.pop_back();
        }
        seg.pb(s);
    }

    for (auto x: seg) {
        double t = val(x);
        for (int i = x.F; i <= x.S; i++) r[i] = t;
    }
    cout.precision(10);
    for (double x: r)cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
