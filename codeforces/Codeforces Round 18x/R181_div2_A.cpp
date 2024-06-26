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

void print(vi &v) {
    cout << v.size() << " ";
    for (int x: v)cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vi v(n), t(n);
    vi a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 0)a.pb(v[i]);
        else if (v[i] < 0)b.pb(v[i]);
        else c.pb(0);
    }

    if (a.empty()) {
        a.pb(b.back());
        b.pop_back();
        a.pb(b.back());
        b.pop_back();
    }
    if (b.size() % 2 == 0) {
        c.pb(b.back());
        b.pop_back();
    }
    print(b);
    print(a);
    print(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
