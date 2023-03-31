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
    vector<ll> v(n / 2), r(n);
    for (ll &x: v)cin >> x;
    ll s, e;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            r[i] = s = i;
            r[n - i - 1] = e = v[i] - i;
        } else {
            if (v[i] - s > e) {
                s = v[i] - e;
            } else {
                e = v[i] - s;
            }
            r[i] = s;
            r[n - i - 1] = e;
        }

    }
    for (ll &x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
