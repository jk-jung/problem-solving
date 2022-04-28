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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    ll r, tot = 0;
    for (ll x: v)tot += b * x;
    r = tot;

    ll last = 0;
    for (int i = 0; i < n; i++) {
        ll dis = v[i] - last;
        tot -= (n - i - 1) * dis * b;
        tot += dis * a;
        last = v[i];
        r = min(r, tot);
    }

    cout << r << endl;
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
