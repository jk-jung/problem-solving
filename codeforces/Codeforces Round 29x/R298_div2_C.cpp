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
    ll n, s;
    cin >> n >> s;
    vi v(n);
    ll ss = 0;
    for (int &x: v)cin >> x, ss += x;

    for (int x: v) {
        ll a = n - 1;
        ll b = ss - x;

        ll ok = 0;
        ll aa = max(s - b, 1ll);
        ll bb = min(s - a, (ll)x);
        if (aa <= bb)ok = bb - aa + 1;

        cout << x - ok << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
