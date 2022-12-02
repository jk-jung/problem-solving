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
    int n;
    cin >> n;
    vi v(n), a, b, c;
    map<ll, int> ck;
    for (int &x: v) {
        cin >> x;
        ck[x] = 1;
        if (x < 0)a.pb(x);
        else if (x == 0)b.pb(x);
        else c.pb(x);
    }
    while (b.size() > 2)b.pop_back();
    v.clear();
    for (int x: a)v.pb(x);
    for (int x: b)v.pb(x);
    for (int x: c)v.pb(x);

    n = v.size();
    if (n < 10) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ll t = (ll) v[i] + v[j] + v[k];
                    if (!ck.count(t)) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        cout << "YES\n";
        return;
    } else cout << "NO\n";
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
