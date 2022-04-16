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

    ll r = 0;
    cin >> n;
    vector<pi> w(n);
    vector<vi> v(n);
    for (int i = 0; i < n; i++)cin >> w[i].F, w[i].S = i, r += w[i].F;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        s--, e--;
        v[s].pb(e);
        v[e].pb(s);
    }
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    vector<ll> rr = {r};
    for (auto[x, i]: w) {
        for (int j = 1; j < v[i].size(); j++) {
            r += x;
            rr.pb(r);
        }
    }
    for (ll x: rr)cout << x << " ";
    cout << endl;
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
