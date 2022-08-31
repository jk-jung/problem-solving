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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    vi vv;
    ll rr = 0;
    for (int i = 0; i < n; i++)if (v[i] > n - k)vv.pb(i), rr += v[i];
    sort(vv.begin(), vv.end());
    ll r = 1;

    for (int i = 1; i < vv.size(); i++)r = (r * (vv[i] - vv[i - 1])) % 998244353;

    cout << rr << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
