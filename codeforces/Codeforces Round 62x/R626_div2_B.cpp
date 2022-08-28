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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    ll r = 0;
    for (int y = 1; y <= n; y++) {
        int x = k / y;
        if (k % y || x > m)continue;

        int ny = 0, nx = 0;
        for (int i = 0, s = 0; i < n; i++) {
            if (a[i])s++;
            else s = 0;
            if (s >= y)ny++;
        }
        for (int i = 0, s = 0; i < m; i++) {
            if (b[i])s++;
            else s = 0;
            if (s >= x)nx++;
        }
        r += (ll) nx * ny;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
