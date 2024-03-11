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
    ll n, r, avg;
    cin >> n >> r >> avg;
    avg *= n;
    vector<pair<ll, ll> > a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].S >> a[i].F;
        sum += a[i].S;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum >= avg) break;
        ll x = min(avg - sum, r - a[i].S);
        ans += x * a[i].F;
        sum += x;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
