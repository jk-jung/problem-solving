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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    k = min(k, m - 1);
    for (int c = 0; c <= k; c++) {
        int t = 1 << 30;
        for (int i = c, j = n - m + c; i <= c + (m - k) - 1; i++, j++) {
            t = min(t, max(v[i], v[j]));
        }
        r = max(r, t);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
