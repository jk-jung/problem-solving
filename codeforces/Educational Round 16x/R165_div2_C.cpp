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

int n, k;
int a[300005];
vector<vector<ll>> d;

ll go(int i, int cnt) {
    if (i == n)return 0;

    ll &r = d[i][cnt];
    if (r != -1)return r;
    r = 1ll << 60;

    ll v = a[i];
    for (int j = i, c = 0; j < n && j - i <= cnt; j++, c++) {
        v = min(v, (ll)a[j]);
        r = min(r, v * (c + 1) + go(j + 1, cnt - c));
    }

    return r;
}

void solve() {
    cin >> n >> k;
    d.clear();
    d.resize(n + 1, vector<ll>(k + 1, -1));
    for (int i = 0; i < n; i++)cin >> a[i];

    cout << go(0, k) << endl;
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
