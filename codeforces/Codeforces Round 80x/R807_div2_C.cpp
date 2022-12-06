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

string s;
vector<pair<ll, ll>> v;

char go(ll k) {
    if (k < s.size()) return s[k];
    k -= s.size();
    for (auto [x, y]: v) {
        ll l = y - x + 1;
        if (k < l) return go(x + k);
        k -= l;
    }
}

void solve() {
    int n, c, q;
    cin >> n >> c >> q >> s;

    v.resize(c);
    for (auto &[x, y]: v)cin >> x >> y, x--, y--;
    while (q--) {
        ll x;
        cin >> x;
        cout << go(x - 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
