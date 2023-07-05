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

bool sf(vi &a, vi &b) {
    if (a.back() == b.back())return a.size() > b.size();
    return a.back() > b.back();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int &x: v)cin >> x;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    reverse(v.begin(), v.end());

    vector<vi> f(n);
    for (int k = 0; k < n; k++) {
        int x = v[k];
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i <= m)f[k].pb(i);
                if (i * i != x && x / i <= m) f[k].pb(x / i);
            }
        }
    }
    vi ck(m + 1);
    int remain = m, r = 1 << 30;
    for (int i = 0, j = 0; i < n; i++) {
        if (i) for (int x: f[i - 1])if (--ck[x] == 0)remain++;
        j = max(j, i);
        while (j < n && remain > 0) {
            for (int x: f[j])if (ck[x]++ == 0)remain--;
            j++;
        }
        if(remain == 0) {
            r = min(r, v[i] - v[j - 1]);
        }
    }
    cout << (r == (1 << 30) ? -1: r) << endl;
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
