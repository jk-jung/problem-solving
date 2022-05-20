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

const ll mod = 998244353;
int n, m;
string s;

pair<ll, string> go(int x) {
    int l_idx = x * 2 + 1;
    int r_idx = x * 2 + 2;

    if (l_idx >= m) return {1ll, string("") + s[x]};

    auto [l_cnt, l_s] = go(l_idx);
    auto [r_cnt, r_s] = go(r_idx);

    ll r = l_cnt * r_cnt % mod;
    if (l_s != r_s) r = (r * 2) % mod;
    if (l_s > r_s) swap(l_s, r_s);

    return {r, string("") + s[x] + l_s + r_s};
}

void solve() {
    cin >> n >> s;
    m = (1 << n) - 1;
    auto [r, _] = go(0);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
