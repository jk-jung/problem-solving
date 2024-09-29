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
    int n;
    cin >> n;
    vi v;
    v.pb(0);
    v.pb(1);
    while (v.back() < n) {
        int m = v.size();
        v.pb(v[m - 1] + v[m - 2]);
    }
    vi r;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] <= n) {
            r.pb(v[i]);
            n -= v[i];
        }
    }

    while (r.size() < 3)r.pb(0);
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
