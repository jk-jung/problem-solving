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
    ll s = 0;
    vector<ll> v(n);
    for (ll &x: v)cin >> x, s += x;
    if (s % 3) {
        cout << 0 << endl;
        return;
    }
    s /= 3;
    ll t = 0;
    vi q;
    for (int i = n - 1; i >= 0; i--) {
        t += v[i];
        if (t == s)q.pb(i);
    }
    t = 0;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        t += v[i];
        if (!q.empty() && q.back() == i)q.pop_back();
        if (!q.empty() && q.back() == i + 1)q.pop_back();
        if (t == s) r += q.size();
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
