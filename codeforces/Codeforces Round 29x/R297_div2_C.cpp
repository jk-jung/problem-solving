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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vi v;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            v.pb(a[i]);
            a[i] = -1;
        } else if (a[i + 1] - 1 == a[i]) {
            v.pb(a[i]);
            a[i] = -1;
        }
    }
    if (v.size() < 2) {
        cout << 0 << endl;
    } else {
        ll r = 0;
        for (int i = 0; i + 1 < v.size(); i += 2)r += (ll) v[i] * v[i + 1];
        cout << r<< endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
