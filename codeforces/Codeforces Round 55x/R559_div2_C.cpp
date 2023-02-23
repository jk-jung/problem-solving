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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (b[0] < a[0]) {
        cout << "-1\n";
        return;
    }

    vi need(m);
    ll r = 0;
    if (b[0] == a[0]) {
        for (ll x: b)r += x;
        for(int i=1;i<n;i++) r += a[i] * m;
    } else {
        for (ll x: b) r += x;
        for(int i=1;i<n;i++) r += a[i] * m;
        r += a[0] - a[1];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
