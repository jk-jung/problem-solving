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
    int n, tot = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, tot += x;
    int s = v[0];
    vi rr = {1};
    for (int i = 1; i < n; i++) {
        if (v[0] >= v[i] * 2)s += v[i], rr.pb(i + 1);
    }
    if (s > tot - s) {
        cout << rr.size() << endl;
        for (int &x: rr)cout << x << " ";
        cout << endl;
    } else cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
