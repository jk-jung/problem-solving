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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = 0;
    for (ll i = 1, s = 0, x = 0, t = 1; i < n; i++, t *= -1) {
        s += ab(v[i] - v[i - 1]) * t;
        r = max(r, s - x);
        x = min(x, s);
    }
    for (ll i = 2, s = 0, x = 0, t = 1; i < n; i++, t *= -1) {
        s += ab(v[i] - v[i - 1]) * t;
        r = max(r, s - x);
        x = min(x, s);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
