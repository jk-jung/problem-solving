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

int v[1000005];
int c[1000005];

int dfs(int x) {
    if (c[x])return 0;
    c[x] = 1;
    return dfs(v[x]) + 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> v[i];

    vi t;
    for (int i = 1; i <= n; i++) {
        if (!c[i])t.pb(dfs(i));
    }
    sort(t.begin(), t.end());
    if (t.size() >= 2) {
        int k = t.back();
        t.pop_back();
        t.back() += k;
    }
    ll r = 0;
    for (int x: t) {
        r += (ll) x * x;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
