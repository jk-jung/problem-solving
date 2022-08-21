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

int a, b, q, m;
vi v;

ll calc(ll x) {
    ll r = v[m - 1] * (x / m);
    return r + v[x % m];
}

void solve() {
    cin >> a >> b >> q;
    m = lcm(a, b);
    v.resize(m);
    for (int i = 0; i < m; i++)v[i] = i % a % b != i % b % a;
    for (int i = 1; i < m; i++)v[i] += v[i - 1];

    while (q--) {
        ll s, e;
        cin >> s >> e;
        cout << calc(e) - calc(s - 1) << ' ';
    }
    cout << '\n';
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
