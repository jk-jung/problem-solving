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

    ll g = 0;
    for (int i = 1; i < n; i++) {
        ll t = a[i] - a[i - 1];
        g = gcd(g, t);
    }

    for (int i = 0; i < m; i++) {
        if (g % b[i] == 0) {
            cout << "YES\n";
            cout << a[0] << " " << i + 1 << endl;
            return ;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
