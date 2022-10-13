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
    vi v(n), d(n + 5, -1), pos(n + 5, -1), r(n + 5, 1 << 30);
    for (int &x: v)cin >> x;

    for (int i = 0; i < n; i++) {
        int x = v[i];
        d[x] = max(d[x], i - pos[x]);
        pos[x] = i;
    }
    for (int x = 1; x <= n; x++)
        d[x] = max(d[x], n - pos[x]);

    for (int x = n; x >=1; x--) {
        r[d[x]] = x;
    }
    for (int i = 1; i <= n; i++)r[i] = min(r[i], r[i - 1]);
    for(int i=1;i<=n;i++)cout << (r[i] > n ? -1 : r[i]) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
