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
    ll n, s;
    cin >> n >> s;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        s -= v[i] - v[0];
    }
    if (s > n * v[0]) {
        cout << -1 << endl;
    } else {
        s = max(0ll, s);
        cout << v[0] - (s + n - 1) / n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
