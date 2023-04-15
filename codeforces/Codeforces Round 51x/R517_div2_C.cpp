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

void p(set<ll> &r) {
    cout << r.size() << endl;
    for (ll x: r)cout << x << " ";
    cout << endl;
}

void solve() {
    ll a, b, flag = 0;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
        flag = 1;
    }
    ll c = a + b;
    ll n = ll(sqrt(c));
    while ((n + 1) * (n + 2) / 2 <= c) n++;

    ll tot = n * (n + 1) / 2;
    ll m = a;
    set<ll> v1, v2;
    for (ll i = n; i >= 1; i--) {
        if (i <= m)m -= i, v1.insert(i), tot -= i;
    }
    for (ll i = 1; i <= n; i++)if (!v1.count(i))v2.insert(i);
    if (flag)swap(v1, v2);
    p(v1);
    p(v2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
