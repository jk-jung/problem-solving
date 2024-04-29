#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    queue<pi> q;
    for (int &x: v)cin >> x;

    ll s = 0;
    ll r = -1, t = 1ll << 60;
    for (int i = 0; i < n; i++) {
        s += v[i];
        q.push(mp(v[i], i + 1));
        if (q.size() > k) {
            s -= q.front().F;
            q.pop();
        }
        if (q.size() == k && s < t) {
            t = s;
            r = q.front().S;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
