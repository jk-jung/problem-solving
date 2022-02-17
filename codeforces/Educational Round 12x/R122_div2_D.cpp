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

int d[1005];

void solve() {
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);

    k = min(k, 15 * n);
    for (int &x: b)cin >> x;
    for (int &x: c)cin >> x;

    vi r(k + 1, -1);
    r[0] = 0;
    int rr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (r[j] == -1) continue;
            int x = j + d[b[i]];
            if (x > k)continue;
            r[x] = max(r[x], r[j] + c[i]);
            rr = max(rr, r[x]);
        }
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 1000; i++)d[i] = 10000000;
    d[0] = d[1] = 0;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            int x = i + i / j;
            d[x] = min(d[x], d[i] + 1);
        }
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
