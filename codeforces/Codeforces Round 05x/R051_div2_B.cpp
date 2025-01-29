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


ll go(int idx, vector<ll> &v, vector<string> &t) {
    if (idx == 3) return v[0];
    ll r = 1ll << 60;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            ll k = t[idx] == "+" ? v[i] + v[j] : v[i] * v[j];
            vector<ll> nv = {k};
            for (int x = 0; x < v.size(); x++) {
                if (x == i || x == j) continue;
                nv.pb(v[x]);
            }
            r = min(r, go(idx + 1, nv, t));
        }
    }
    return r;
}

void solve() {
    vector<ll> v(4);
    vector<string> t(3);
    map<char, int> c;
    for (auto &x: v)cin >> x;
    for (auto &x: t)cin >> x;
    cout << go(0, v, t) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
