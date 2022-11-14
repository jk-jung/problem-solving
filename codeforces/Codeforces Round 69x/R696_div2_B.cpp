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

ll f(ll i) {
    for (;; i++) {
        bool ok = true;
        for (ll k = 2; k * k <= i; k++)if (i % k == 0)ok = false;
        if (ok) return i;
    }
}

void solve() {
    ll x;
    cin >> x;
    ll a = f(1 + x);
    ll b = f(a + x);

    cout << a * b << endl;
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
