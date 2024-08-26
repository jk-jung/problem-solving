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
    int n, d, m;
    cin >> n >> d >> m;
    // n, d, m;

    vi r;
    int kk = 0;
    if (n % 2) {
        kk = max(1, min(m, d));
        d -= kk;
        n--;
    }

    for (int i = 0; i < n; i += 2) {
        int need = min(ab(d), m - 1);
        int x = need + 1, y = 1;
        if (d < 0)swap(x, y);
        r.pb(x);
        r.pb(y);
        d -= (x - y);
    }
    if (kk)r.pb(kk);
    if(d == 0)
        for (int x: r)cout << x << " ";
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
