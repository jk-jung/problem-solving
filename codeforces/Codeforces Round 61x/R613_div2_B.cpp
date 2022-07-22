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
    int n;
    cin >> n;
    vi v(n);

    ll s = 0;

    map<ll, int> t;
    for (int &x: v)cin >> x, s += x;

    t[0] = -1;
    ll ss = 0;
    for (int i = 0; i < n; i++) {
        ss += v[i];
        auto [x, y] = *t.begin();
        ll val = ss - x;
        if (val >= s) {
            if (y == -1 && i == n - 1)continue;
            cout << "NO\n";
            return;
        }
        t[ss] = i;
    }
    cout << "YES\n";
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
