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

ll f(ll x) {
    ll base = 1;
    ll cnt = 0;
    while (base <= x) {
        if (base > x / 10) {
            if (x >= base * 2) cnt += base;
            else cnt += x - base + 1;
            break;
        } else {
            cnt += base;
        }
        base *= 10;
    }
    return cnt;
}

double calc(ll a, ll b) {
    return double(f(b) - f(a - 1)) / double(b - a + 1);
}

double d[1005][1005];

void solve() {
    int n;
    cin >> n;
    vector<double> v;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v.pb(calc(a, b));
    }
    int k;
    cin >> k;
    int th = (n * k + 99) / 100;


    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = d[i - 1][j] * (1 - v[i - 1]);
            if (j)d[i][j] += d[i - 1][j - 1] * v[i - 1];
        }
    }
    double r = 0;
    for (int i = th; i <= n; i++)r += d[n][i];
    printf("%.9lf\n", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
