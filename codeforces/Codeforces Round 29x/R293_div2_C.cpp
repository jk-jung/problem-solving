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
    vi a(n), b(m), p(n + 1), q(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
        q[i] = a[i];
    }
    for (int i = 0; i < m; i++) cin >> b[i];
    ll r = 0;
    for (int x: b) {
        r += p[x] / k + 1;
        if (p[x] == 0) continue;
        int y = q[p[x] - 1];
        swap(p[x], p[y]);
        swap(q[p[x]], q[p[y]]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
