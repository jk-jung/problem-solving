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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    ll r = 0;
    map<vi, int> c;
    for (int i = 2; i < n; i++) {
        vi t;
        t.pb(v[i - 2]);
        t.pb(v[i - 1]);
        t.pb(v[i]);

        r -= c[t] * 3;
        for (int k = 0; k < 3; k++) {
            int x = t[k];
            t[k] = 0;
            r += c[t];
            c[t]++;
            t[k] = x;
        }
        c[t]++;
    }
    cout << r << endl;
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
