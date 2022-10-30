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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    int ii = 0;
    for (auto &x: v)cin >> x.F, x.S = ++ii;
    sort(v.begin(), v.end());

    ll m = (k + 1) / 2;
    for (ll i = n - 1; i >= 0; i--) {
        if (v[i].F > k)continue;
        if (v[i].F >= m) {
            cout << "1\n" << v[i].S << endl;
            return;
        } else {
            vi r;
            for (ll j = i; j >= 0; j--) {
                m -= v[j].F;
                r.pb(v[j].S);
                if (m <= 0)break;
            }
            if (m > 0) {
                cout << "-1\n";
            } else {
                cout << r.size() << endl;
                for (int x: r)cout << x << " ";
                cout << endl;
            }
            return;
        }
    }
    cout << "-1\n";
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
