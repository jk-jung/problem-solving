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

struct Ball {
    double x, v, m;
    int idx;

    Ball(double x, double v, double m, int idx) : x(x), v(v), m(m), idx(idx) {}
};

bool sf1(Ball &a, Ball &b) {
    if(ab(a.x - b.x) < 1e-9)return a.v < b.v;
    return a.x < b.x;
}

bool sf2(Ball &a, Ball &b) { return a.idx < b.idx; }

vector<Ball> v;
int n, t;

double calc_next_collision() {
    sort(v.begin(), v.end(), sf1);
    double min_t = 1e18;
    for (int i = 0; i < n - 1; i++) {
        double dx = v[i + 1].x - v[i].x;
        double dv = v[i].v - v[i + 1].v;
        if (dv < 1e-9 || dx < 1e-9)
            continue;

        double k = dx / dv;
        if (k > 0 && k < min_t)
            min_t = k;
    }
    return min_t;
}

void simulate(double dt) {
    sort(v.begin(), v.end(), sf1);
    for (Ball &b: v)
        b.x += b.v * dt;
    for (int i = 1; i < n; i++) {
        Ball &a = v[i - 1];
        Ball &b = v[i];
        if (ab(a.x - b.x) < 1e-9) {
            double n1 = (a.m - b.m) * a.v + 2 * b.m * b.v;
            double n2 = (b.m - a.m) * b.v + 2 * a.m * a.v;
            a.v = n1 / (a.m + b.m);
            b.v = n2 / (a.m + b.m);
        }
    }
}

void solve() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        double x, y, m;
        cin >> x >> y >> m;
        v.pb(Ball(x, y, m, i));
    }
    double current = 0;
    while (current + 1e-9 < t) {
        double dt = min(calc_next_collision(), t - current);
        current += dt;
        simulate(dt);
    }
    sort(v.begin(), v.end(), sf2);
    for (Ball &b: v)
        printf("%.10lf\n", b.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
