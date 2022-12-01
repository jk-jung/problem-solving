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

int n, m, k;

bool can(deque<pair<ll, ll>> &q, ll x) {
    for (auto [a, b]: q) {
        ll c = min(b, x / a);
        ll cc = c;
        while (cc && m != 1 && cc % m == 0) {
            cc /= m;
        }
        if (cc != 1) return false;
        b -= c;
        x -= a * c;
        if (x == 0)return true;
        if (b && x) return false;
        return false;
    }
    return false;
}

void process(deque<pair<ll, ll>> &q, ll x) {
    while (!q.empty()) {
        auto &[a, b] = q.front();
        ll c = min(b, x / a);
        b -= c;
        x -= a * c;
        if (b == 0) q.pop_front();
        if (x == 0)return;
    }
}



void solve() {

    cin >> n >> m;
    vi a(n);
    for (int &x: a)cin >> x;
    cin >> k;
    vi b(k);
    for (int &x: b)cin >> x;

    int pos = 0;
    deque<pair<ll, ll>> cur;
    for (int x: b) {
        while (!can(cur, x)) {
            if (pos == a.size()) {
                cout << "NO\n";
                return;
            }
            ll t = a[pos++];
            ll cnt = 1;
            while (t % m == 0) cnt *= m, t /= m;
            if (cur.empty() || cur.back().F != t)cur.pb({t, cnt});
            else cur.back().S += cnt;
        }
        process(cur, x);
    }
    cout << (cur.empty() && pos == a.size() ? "YES\n" : "NO\n") << endl;
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
