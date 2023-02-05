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

ll d[100005];

ll f(ll x) {
    if (x <= 1) return 1;
    if (d[x] != -1) return d[x];
    return d[x] = (f(x - 2) + f(x - 1)) % 1000000007;
}

void solve() {
    memset(d, -1, sizeof(d));
    ll n, m;
    cin >> n >> m;

    cout << 2 * (f(n) + f(m) - 1) % 1000000007 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
