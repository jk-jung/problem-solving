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
    vector<ll> v(n);
    for (auto &x: v)cin >> x;
    set<ll> s;
    for (auto x: v) {
        for (int i = 0; i < 100; i++) {
            ll t = x % k;
            if (t > 1 || (t && s.count(i))) {
                cout << "NO\n";
                return;
            }
            if (t)s.insert(i);
            x /= k;
        }
    }
    cout << "YES\n";
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
