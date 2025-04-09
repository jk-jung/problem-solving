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


void solve() {
    int l, d, g, r;
    double v;
    cin >> l >> d >> v >> g >> r;
    double t = d / v;
    double remain = t - int(t) / (g + r) * (g + r);
    if (remain < g) {
        printf("%.10lf", double(l) / v);
    } else {
        double k = (int(t / (g + r)) + 1) * (g + r) + (l - d) / v;
        printf("%.10lf", k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
