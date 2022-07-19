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

int n;

void solve() {
    cin >> n;
    vi v(n);
    vector<ll> c(n), s(n + 5);
    for (int &x: v)cin >> x;
    for (int i = 1; i < n - 1; i++) {
        int t = max(v[i - 1], v[i + 1]) + 1;
        c[i] = max(0, t - v[i]);
    }
    for (int i = n - 2; i >= 0; i -= 2)
        s[i] = c[i] + s[i + 2];

    ll r = 1ll << 50, cur = 0;
    if(n % 2 == 0)r = s[2];
    for (int i = 1; i < n - 1; i += 2) {
        cur += c[i];
        if (n % 2 == 0 && i + 3 < n - 1)
            r = min(r, cur + s[i + 3]);

    }
    r = min(r, cur);
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
