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
    ll n, d;
    cin >> n >> d;
    vector<ll> v;

    ll x = 1;
    while (n) {
        ll i = 1;
        for (; (1ll << i) - 1 <= n; i++);
        i--;
        n -= (1ll << i) - 1;
        for (ll k = 0; k < i; k++)v.pb(x);
        x += d;
    }
    cout << v.size() << endl;
    for (ll y: v)cout << y << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
