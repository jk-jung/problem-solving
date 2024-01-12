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

int n, p;

double f(pi x) {
    int a = x.S / p;
    int b = (x.F - 1) / p;
    return (a - b) / double(x.S - x.F + 1);
}

void solve() {

    cin >> n >> p;

    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;

    double r = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double a = f(v[i]);
        double b = f(v[j]);
        r += a * 1000 + b * 1000 - a * b * 1000;
    }
    printf("%.10lf\n", r * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
