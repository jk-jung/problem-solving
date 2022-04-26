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

bool can(vi &v, int m) {
    int rest = m - (int)v.size();
    int i = 0;
    for (int x: v) {
        int need = max(0, x - m + i);
        rest -= need;
        i ++;
    }
    return rest >= 0;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> v(n + 1);
    vi t;
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        v[x].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size())t.pb(v[i].size());
    }
    t.pb(1);
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    int s = t.size(), e = n, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (can(t, m))e = m - 1, r = m;
        else s = m + 1;
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
