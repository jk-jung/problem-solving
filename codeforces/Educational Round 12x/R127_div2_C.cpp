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

ll n, k;

void solve() {
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());
    ll i, tot;
    for (i = 0, tot = 0; i < n; i++) {
        if (tot + v[i] > k)break;
        tot += v[i];
    }
    ll r = 0, tot_days = 0;
    for (i = i - 1; i >= 0; i--) {
        ll c = i + 1;
        ll t = tot + tot_days * c;
        ll left = (k - t);
        if(left >= 0) {
            ll days = left / c + 1;
            r += days * c;
            tot_days += days;
        }
        tot -= v[i];
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
