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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), a(n), b(n);
    for (ll &x: v)cin >> x;

    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + (v[i - 1] > v[i] ? v[i - 1] - v[i] : 0);
    }
    for (int i = n - 2; i >= 0; i--) {
        b[i] = b[i + 1] + (v[i + 1] > v[i] ? v[i + 1] - v[i] : 0);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if(x < y) cout << a[y] - a[x] << endl;
        else cout << b[y] - b[x] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
