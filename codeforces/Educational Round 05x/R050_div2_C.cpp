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

typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

vector<ll> v;

void gen(ll idx = 0, ll x = 0, ll cnt = 0) {
    if (idx == 19) {
        v.pb(x);
        return;
    }
    gen(idx + 1, x * 10, cnt);
    if (cnt < 3)
        for (int i = 1; i <= 9; i++)gen(idx + 1, x * 10 + i, cnt + 1);
}

void solve() {
    ll s, e;
    cin >> s >> e;
    s = lower_bound(v.begin(), v.end(), s) - v.begin();
    e = lower_bound(v.begin(), v.end(), e + 1) - v.begin();
    cout << e - s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    gen(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
