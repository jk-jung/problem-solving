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
    ll n;
    cin >> n;

    ll c = 2;
    vector<ll> v = {2};
    for (int i = 3; c <= n; c *= i++)
        v.pb(c);

    int r = 1 << 30;
    int m = (int) v.size();
    for (int i = 0; i < (1 << m); i++) {
        ll cur = 0;
        int t = 0;
        for (int k = 0; k < m; k++)if (i >> k & 1)t++, cur += v[k];
        if (cur > n)continue;
        r = min(r, __builtin_popcountll(n - cur) + t);
    }

    if (r == 1 << 30)r = -1;
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
