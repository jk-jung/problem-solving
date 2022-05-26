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


ll read() {
    string s;
    cin >> s;
    ll r = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)if (s[i] == '1') r |= 1ll << i;
    return r;
}

/*
 1
 4 3
000
111
100
011

 */

void solve() {
    int n, t;
    cin >> t >> n;
    vector<ll> v(t);
    for (int i = 0; i < t; i++)v[i] = read();

    ll s = 0, e = (1ll << n) - 1, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll a = m;
        ll b = (1ll << n) - m;
        for (ll x: v) {
            if (x < m) a--;
            else b--;
        }

        if (a < b)r = m, s = m + 1;
        else e = m - 1;
    }
    for(int i=n-1;i>=0;i--)cout << (r >> i & 1);
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
