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

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);

    ll s = 0, xo = 0;
    for (ll &x: v)cin >> x, s += x, xo ^= x;
    ll a = 1ll << 50;
    if (s % 2 == 1)a++;
    s += a;
    xo ^= a;

    ll b = (xo * 2 - s) / 2;
    cout << 3 << endl;
    cout << a << " " << b << " " << b << endl;
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
