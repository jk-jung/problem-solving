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
    int n, m;
    cin >> n >> m;
    set<int> v;
    vector<tuple<int, int, int>> t(m);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v.insert(x);
    }
    for (auto &[x, y, z]: t)cin >> x >> y >> z;
    for (auto [a, b, c]: t) {
        auto i = v.lower_bound(b);
        if(i == v.end())i--;
        ll y1 = *i;
        if(i != v.begin())i--;
        ll y2 = *i;
        if((b - y1) * (b - y1) - 4ll * a * c < 0) cout <<"YES\n" << y1 << endl;
        else if((b - y2) * (b - y2) - 4ll * a * c < 0) cout <<"YES\n" << y2 << endl;
        else cout <<"NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
