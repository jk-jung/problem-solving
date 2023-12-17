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
    int n;
    ll w, a, b;
    cin >> n >> w >> a >> b;
    vector<pi> v(n);
    for (auto &t: v)cin >> t.F >> t.S;

    bool ok = true;
    double mm = 0;
    for (int i = 0; i < n; i++) {
        ll y = v[i].F * b;
        if (y < v[i].S * a)ok = false;
        mm = min(mm, v[i].S - v[i].F * b / (double) a);
    }

    if (ok) {
        printf("%.10lf\n", w / (double) b);
    }else {
        printf("%.10lf\n", (w - mm) / (double) b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
