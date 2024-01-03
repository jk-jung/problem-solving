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

vector<vector<pair<int, string> > > v;

void solve() {
    int n, m;
    cin >> n >> m;

    v.resize(m);
    for (int i = 0; i < n; i++) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        v[b - 1].pb(mp(c, a));
    }
    for (auto &x: v) {
        sort(x.rbegin(), x.rend());
        if (x.size() > 2 && x[1].F == x[2].F) {
            cout << "?" << endl;
        } else {
            cout << x[0].S << " " << x[1].S << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
