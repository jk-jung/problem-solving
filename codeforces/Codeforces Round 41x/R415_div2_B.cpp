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

int f(pi x) {
    return min(x.S, x.F * 2) - min(x.S, x.F);
}

bool sf(pi &a, pi &b) {
    return f(a) > f(b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end(), sf);

    ll r = 0;
    for (int i = 0; i < n; i++) {
        pi x = v[i];
        if (i < k)r += min(x.S, x.F * 2);
        else r += min(x.S, x.F);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
