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
    ll x, y, s, e;
    cin >> x >> y >> s >> e;

    vector<ll> v;
    for (ll i = 1;; i *= x) {
        for (ll j = 1;; j *= y) {
            ll t = i + j;
            if (s <= t && t <= e) v.pb(t);
            if (j > e / y)break;
        }
        if (i > e / x)break;
    }
    v.pb(s - 1);
    v.pb(e + 1);
    sort(v.begin(), v.end());
    ll r = 0;
    for (int i = 1; i < v.size(); i++)r = max(r, v[i] - v[i - 1] - 1);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
