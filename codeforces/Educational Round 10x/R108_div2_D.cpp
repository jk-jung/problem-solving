#include <string.h>
#include <stdio.h>
#include <math.h>
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

ll s[5005];
int n;

ll calc(int x, int y) {
    ll r = s[n - 1] - s[y];
    if (x)r += s[x - 1];
    return r;
}

void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;

    for (int i = 0; i < n; i++) {
        s[i] += a[i] * b[i];
        if (i) s[i] += s[i - 1];
    }

    ll r = s[n-1];
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (int x = i, y = i; x >= 0 && y < n; x--, y++) {
            cur += a[x] * b[y];
            if(x != y) cur += a[y] * b[x];
            r = max(r, calc(x, y) + cur);
        }

        cur = 0;
        for (int x = i, y = i + 1; x >= 0 && y < n; x--, y++) {
            cur += a[x] * b[y];
            if(x != y) cur += a[y] * b[x];
            r = max(r, calc(x, y) + cur);
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
