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
    double a, b;
    cin >> a >> b;
    int m;
    cin >> m;

    double r = 1e30;
    for (int i = 0, x, y, v; i < m; i++) {
        cin >> x >> y >> v;
        x -= a;
        y -= b;
        r = min(r, sqrt(double(x * x + y * y)) / v);
    }
    printf("%.10lf\n", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
