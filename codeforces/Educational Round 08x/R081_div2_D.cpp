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

ll x, n, g;
ll r;
map<ll, ll> fn, fg;

map<ll, ll> fac(ll m) {
    map<ll, ll> f;
    for (ll i = 2; i * i <= m; i++) {
        while (m % i == 0)m /= i, f[i]++;
    }
    if (m > 1)f[m]++;
    return f;
}

void check(map<ll, ll>::iterator it, ll cur = 1, ll cnt = 0) {
    if (it == fn.end()) {
        if (cur % g != 0)return;
        ll c = 0;
        for (auto i = fg.begin(); i != fg.end(); i++)c += i->S;

        int ck = 1;
        if ((cnt - c) % 2 == 1)ck = -1;
        r += n / cur * ck;
        return;
    }
    for (int i = 0; i <= it->S; i++) {
        it++;
        check(it, cur, cnt);
        it--;

        if (i == fg[it->F] + 1)break;
        cur *= it->F;
        cnt++;
    }
}

void solve() {
    cin >> x >> n;
    g = gcd(x, n);

    fn = fac(n);
    fg = fac(g);

    r = 0;
    check(fn.begin());
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
