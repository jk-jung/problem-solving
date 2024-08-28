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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> r(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<ll> t(m, 1ll << 40);

        ll idx = -(1ll << 40);;
        for (int j = 0; j < m * 2; j++) {
            if (s[j % m] == '1')idx = j;
            t[j % m] = min(t[j % m], j - idx);
        }
        idx = 1ll << 40;
        for (int j = m * 2 - 1; j >= 0; j--) {
            if (s[j % m] == '1')idx = j;
            t[j % m] = min(t[j % m], idx - j);
        }
        for (int j = 0; j < m; j++)r[j] += t[j];
    }
    ll rr = 1 << 30;
    for (ll x: r)rr = min(rr, x);
    if (rr >= (1 << 30))rr = -1;
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
