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
    string a, b;
    cin >> n >> a >> b;
    vector<pi> r;
    vi x, y, xx, yy;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == 'a') x.pb(i + 1);
            else y.pb(i + 1);
        } else {
            if (a[i] == 'a')xx.pb(i + 1);
            else yy.pb(i + 1);
        }
    }
    if (x.size() % 2 == 1 && y.size() % 2 == 1) {
        r.pb({x.back(), x.back()});
        y.pb(x.back());
        x.pop_back();
    }
    if (x.size() % 2 || y.size() % 2) cout << -1 << endl;
    else {
        cout << x.size() / 2 + y.size() / 2 + r.size() << endl;
        for (auto [p, q]: r) cout << p << " " << q << endl;
        for (int i = 0; i < x.size(); i += 2)cout << x[i] << " " << x[i + 1] << endl;
        x = y;
        for (int i = 0; i < x.size(); i += 2)cout << x[i] << " " << x[i + 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
