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
    vector<pi> v(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i].F = x;
        v[i].S = i;
        s += x;
    }
    sort(v.begin(), v.end());
    vi r;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (s - v[n - 1].F - v[n - 2].F == v[n - 2].F)r.pb(v[i].S + 1);
        } else {
            if (s - v[n - 1].F - v[i].F == v[n - 1].F) r.pb(v[i].S + 1);
        }
    }
    cout << r.size() << endl;
    for (int &x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
