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
    cin >> n;
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    double s = 0, e = 1 << 30;
    for (int c = 0; c < 300; c++) {
        double m = (s + e) / 2;
        bool ok = false;

        double l = a[0] - b[0] * m;
        double r = a[0] + b[0] * m;
        for (int i = 1; i < n; i++) {
            double ll = a[i] - b[i] * m;
            double rr = a[i] + b[i] * m;
            if (ll > r || l > rr)break;
            l = max(l, ll);
            r = min(r, rr);
            if (i == n - 1)ok = true;
        }

        if (ok)e = m;
        else s = m;
    }

    printf("%.10lf\n", s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
