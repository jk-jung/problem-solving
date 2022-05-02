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
    map<int, vi> s;
    int idx = 0;
    for (int &x: v)cin >> x, s[x].pb(++idx);
    if (s.size() == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int last = 0;
    vector<pi> r;
    for (auto &[k, t]: s) {
        if (last)r.pb({last, t[0]});
        last = t[0];
    }
    for (auto &[k, t]: s) {
        for (int i = 1; i < t.size(); i++)
            r.pb({t[i], last});
        last = t[0];
    }
    for (auto [a, b]: r)cout << a << " " << b << '\n';
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
