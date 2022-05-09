#include <string.h>
#include <stdio.h>
#include <math.h>
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


ll calc(ll a, ll b, ll x, ll y, ll n) {
    ll t = min(a - x, n);
    a -= t;
    n -= t;
    b = max(y, b - n);
    return a * b;
}

void solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll r1 = calc(a, b, x, y, n);
    ll r2 = calc(b, a, y, x, n);

    cout << min(r1, r2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
