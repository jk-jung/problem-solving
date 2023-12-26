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

pair<double, double> a, b, c;

double dis(pair<double, double> x, pair<double, double> y) {
    return sqrt((x.F - y.F) * (x.F - y.F) + (x.S - y.S) * (x.S - y.S));
}

void solve() {
    double ax, ay, bx, by, cx, cy;
    int n;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> n;
    a = mp(ax, ay);
    b = mp(bx, by);
    c = mp(cx, cy);
    vector<pair<double, double>> v(n);
    double r = 0;
    for (auto &t: v) {
        cin >> t.F >> t.S;
        r += dis(t, c) * 2;
    }
    double rr = 1e18;
    vector<pair<double, int>> vv;
    for (int i = 0; i < n; i++) {
        pi t = v[i];
        rr = min(rr, r - dis(t, c) + dis(t, a));
        rr = min(rr, r - dis(t, c) + dis(t, b));
        vv.pb(mp(-dis(t, c) + dis(t, b), i));
    }
    sort(vv.begin(), vv.end());

    for (int i = 0; i < n; i++) {
        pi t = v[i];
        for(auto [d, j]: vv){
            if(j == i) continue;
            rr = min(rr, r - dis(t, c) + dis(t, a) + d);
            break;
        }
    }

    printf("%.10lf", rr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
