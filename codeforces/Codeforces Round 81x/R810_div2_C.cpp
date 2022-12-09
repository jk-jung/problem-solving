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


bool check(int n, int m, vi &v) {
    ll r = 0;
    bool flag = false;
    vi t;
    for (int x: v) {
        if (x / m >= 2) t.pb(x / m);
    }
    sort(t.begin(), t.end());
    int nn = n;
    for (int x: t) {
        if (nn == 1) {
            if (x >= 3)nn = 0;
        } else {
            nn -= x;
        }
        if (nn <= 0)return true;
    }
    return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi v(k);
    for (int &x: v)cin >> x;

    cout << (check(n, m, v) || check(m, n, v) ? "Yes" : "No") << endl;
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
