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
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    vector<vi> d(n * 2, vi(n + 1, 1 << 30));

    int r = 1 << 30;
    d[0][0] = 0;
    for (int t = 1; t < n * 2; t++) {
        d[t][0] = 0;
        for (int i = 1; i <= n; i++) {
            d[t][i] = min(d[t - 1][i], d[t - 1][i - 1] + ab(t - v[i - 1]));
        }
        r = min(r, d[t][n]);
    }
    cout << r << endl;
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
