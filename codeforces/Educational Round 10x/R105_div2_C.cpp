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


int calc(vi &a, vi &b) {
    int n = a.size();
    int m = b.size();

    int k = n - 1, r = 0, already = 0;
    for (int e = m - 1, s = m - 1; e >= 0; e--) {
        while (k >= 0 && a[k] > b[e]) k--;
        if(k == -1) break;
        int ss = b[e] - k;

        while (s >= 0 && b[s] >= ss) s--;
        r = max(r, e - s + already);
        if(a[k] == b[e]) already++;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a, b, c, d;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x < 0)a.pb(-x);
        else b.pb(x);
    }
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        if (x < 0)c.pb(-x);
        else d.pb(x);
    }
    reverse(a.begin(), a.end());
    reverse(c.begin(), c.end());

    cout << calc(a, c) + calc(b, d) << endl;
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
