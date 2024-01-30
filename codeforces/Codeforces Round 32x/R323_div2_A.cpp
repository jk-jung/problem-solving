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
    cin >> n;

    vector<pi> v(n * n);
    set<int> a, b;
    vi r;
    int c = 0;
    for (auto [x, y]: v) {
        cin >> x >> y;
        ++c;
        if (!a.count(x) && !b.count(y)) {
            a.insert(x);
            b.insert(y);
            r.pb(c);
        }
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
