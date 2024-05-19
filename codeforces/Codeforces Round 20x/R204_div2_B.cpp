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
    vi v(n);
    for (int &x: v)cin >> x;
    vector<pi> r;
    map<int,vi> c;
    for (int i = 0; i < n; i++) {
        c[v[i]].pb(i);
    }
    for(auto &[k, v]: c) {
        if(v.size() == 1)r.pb(mp(k, 0));
        else {
            bool ok = true;
            int d = v[1] - v[0];
            for(int i = 1; i < v.size(); i++) {
                if(v[i] - v[i - 1] != d) {
                    ok = false;
                    break;
                }
            }
            if(ok)r.pb(mp(k, d));
        }
    }
    cout << r.size() << endl;
    for(auto [k, v]: r) {
        cout << k << " " << v << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
