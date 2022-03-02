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

ll d[2005][2005];
vector<ll> v;

ll go(int s, int e) {
    if (s >= e) return 0;
    ll &r = d[s][e];
    if (r != -1)return r;
    r = 1ll << 60;

    r = min(go(s + 1, e), go(s, e - 1)) + v[e] - v[s];
    return r;
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());

    memset(d, -1, sizeof(d));
    cout << go(0, n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
