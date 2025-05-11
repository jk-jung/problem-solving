#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (auto &[x, y]: v)cin >> y >> x;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll r = 0;
    for (auto [x, y]: v) {
        ll cnt = min(n, y);
        r += cnt * x;
        n -= cnt;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
