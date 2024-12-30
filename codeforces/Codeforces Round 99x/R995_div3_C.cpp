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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(m), c(k);
    for (int &x: v)cin >> x;
    for (int &x: c)cin >> x;
    if (k == n) {
        for (int i = 0; i < m; i++)cout << 1;
    } else if (k != n - 1) {
        for (int i = 0; i < m; i++)cout << 0;
    } else {
        sort(c.begin(), c.end());
        int r = n;
        for (int i = 0; i < k; i++) {
            if (c[i] != i + 1) {
                r = i + 1;
                break;
            }
        }
        for (int x: v) {
            if (r == x)cout << 1;
            else cout << 0;
        }
    }
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
