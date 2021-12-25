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


ll calc(vi &v, int k) {
    int n = v.size();
    ll r = 0;
    for (int i = n - 1; i >= 0; i -= k) {
        r += v[i] * 2;
    }
    return r - v.back();
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x < 0)a.pb(-x);
        if (x > 0)b.pb(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll r;
    if (a.size() == 0 && b.size() == 0) r = 0;
    else if (a.size() == 0) r = calc(b, k);
    else if (b.size() == 0) r = calc(a, k);
    else {
        ll t = calc(a, k) + calc(b, k);
        r = t + min(a.back(), b.back());
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
