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

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

ll M = 1000000000000000000ll;
vector<ll> a;

void solve() {
    ll n, m;
    cin >> n;
    m = n;
    ll t = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] <= n) {
            n -= a[i];
            t |= (1ll << i);
        }
    }
    if (n == 0)cout << m << endl;
    else {
        t++;
        ll r = 0;
        for (int i = 0; i < a.size(); i++)if(t >> i & 1)r += a[i];
        cout << r << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (ll x = 1; x <= M * 3; x *= 3) a.pb(x);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
