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
    map<string, pi> c;
    string t;
    vector<pair<pi, string> > v;
    int r = 1 << 30;
    for (int i = 0; i < n; i++) {
        string x;
        int y;
        cin >> x >> y;
        c[x].F -= y;
        c[x].S = i;
        v.pb(mp(mp(c[x].F, i), x));
    }
    for (auto &[x, y]: c) {
        r = min(r, y.F);
    }
    for (auto &[x, y]: v) {
        if (x.F <= r && r == c[y].F) {
            cout << y << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
