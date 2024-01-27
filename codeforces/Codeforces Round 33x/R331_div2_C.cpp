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

map<int, vector<pi>> ck;
set<pi> s;

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);

    for (auto &x: v) {
        cin >> x.F >> x.S;
        ck[x.S - x.F].pb(x);
    }
    for (auto &x: ck) sort(x.S.rbegin(), x.S.rend());

    vi w(n);
    for (int &x: w)cin >> x;

    vector<pi> r;

    for (int x: w) {
        if (ck[x].empty()) {
            cout << "NO" << endl;
            return;
        }
        pi a = ck[x].back();
        r.pb(a);
        ck[x].pop_back();
        if (ck[x].empty())ck.erase(x);

        if(a.F > 0 && s.find({a.F - 1, a.S}) == s.end()) {
            cout << "NO" << endl;
            return;
        }
        if(a.S > 0 && s.find({a.F, a.S - 1}) == s.end()) {
            cout << "NO" << endl;
            return;
        }
        s.insert(a);
    }
    cout << "YES" << endl;
    for (auto [x, y]: r) {
        cout << x << " " << y << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
