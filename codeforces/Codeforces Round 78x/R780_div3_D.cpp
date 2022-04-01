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


pair<int, pi> calc(vi &v, int e, int m) {
    int n = v.size();
    if(n == 0) return {-1, {-1, -1}};
    int s = e - n;
    e = m - e;

    int neg = 0, two = 0;
    for (int x: v) {
        if (x < 0) neg++;
        if (ab(x) == 2)two++;
    }

    if (neg % 2 == 0) return {two, {s, e}};
    int a = 0, ap = 0, b = 0, bp = 0;

    for (int i = 0; i < n; i++) {
        ap++;
        if (ab(v[i]) == 2)a++;
        if (v[i] < 0)break;
    }
    for (int i = n - 1; i >= 0; i--) {
        bp++;
        if (ab(v[i]) == 2)b++;
        if (v[i] < 0)break;
    }

    if (a < b) return {two - a, {ap + s, e}};
    return {two - b, {s, bp + e}};
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    vi cur;
    pair<int, pi> r = {0, {n, 0}};
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            r = max(r, calc(cur, i, n));
            cur.clear();
        }else cur.pb(v[i]);
    }
    r = max(r, calc(cur, n, n));
    cout << r.S.F <<" " << r.S.S << endl;
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
