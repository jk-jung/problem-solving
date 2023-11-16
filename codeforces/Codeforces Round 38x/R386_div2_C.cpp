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
    double s, x1, x2, t1, t2, p, d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    double r = ab(x1 - x2) * t2;

    if (t1 >= t2) {
        printf("%d", (int)r);
        return;
    }
    double dd = x2 - x1;
    double t = 0;
    if (dd * d < 0) {
        if (d < 0) {
            t = p * t1;
            p = 0;
        } else {
            t = (s - p) * t1;
            p = s;
        }
    }
    if (dd < 0 && p < x1) {
        t += (p + s) * t1;
        p = s;
    }
    if (dd > 0 && p > x1) {
        t += (s - p + s) * t1;
        p = 0;
    }
    double tt = (t / t2 + ab(p - x1)) / (1 / t1 - 1 / t2) + t;
    tt += ab(ab(x2 - x1) - tt / t2)  * t1;
    r = min(r, tt);


    printf("%d", (int)ceil(r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
