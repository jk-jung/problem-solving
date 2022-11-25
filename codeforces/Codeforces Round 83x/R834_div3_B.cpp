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

void solve() {
    ll n, s, m = -1;
    cin >> n >> s;
    vector<ll> v(500);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[x] = 1;
        m = max(m, x);
    }
    for (int i = 1; i < m; i++)if (!v[i])s -= i;
    while (s > 0) {
        m++;
        s -= m;
    }
    cout << (s == 0 ? "YES" : "NO") << endl;
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
