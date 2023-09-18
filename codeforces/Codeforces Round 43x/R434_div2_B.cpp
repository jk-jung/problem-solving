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
    vector<pi> v(m);
    n--;
    for (auto &[x, y]: v)cin >> x >> y, x--, y--;
    set<int> r;
    for (int k = 1; k <= 100; k++) {
        bool ok = true;
        for (auto [x, y]: v) {
            if (x / k != y)ok = false;
        }
        if (ok){
            r.insert(n / k + 1);
        }
    }
    if (r.size() == 1)cout << *r.begin() << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
