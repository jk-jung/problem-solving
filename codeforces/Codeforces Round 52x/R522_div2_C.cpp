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

vi go(int z, vi &v) {
    vi r = {z};
    for (int i = 1; i < v.size() - 1; i++) {
        int x = v[i], y = v[i + 1];
        z = v[i - 1];
        int f = r.back();
        if (x == y) {
            if (z == x) r.pb(f == 2 ? 3 : 2);
            else if (z < x)r.pb(f + 1);
            else r.pb(f - 1);
        } else if (x < y) {
            if(z == x)r.pb(f == 1 ? 2 : 1);
            else if (z > x)r.pb(min(1, f - 1));
            else r.pb(f + 1);
        } else if (x > y) {
            if(z == x)r.pb(f == 5 ? 4 : 5);
            else if (z < x)r.pb(max(f + 1, 5));
            else r.pb(f - 1);
        }
        if (r.back() < 1 || r.back() > 5) {
            return vi();
        }
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    v.pb(v.back());
    for (int i = 1; i <= 5; i++) {
        vi r = go(i, v);
        if (!r.empty()) {
            for (int y: r)cout << y << " ";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
