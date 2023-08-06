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
    ll k, d, t;
    cin >> k >> d >> t;

    d = ((k + d - 1) / d) * d;

    t *= 2;
    ll x = k * 2 + (d - k);

    double r = (t / x) * d;
    ll rest = t % x;
    if (rest <= k * 2) r += rest / 2.0;
    else r += k + (rest - k * 2);

    printf("%.10lf\n", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
