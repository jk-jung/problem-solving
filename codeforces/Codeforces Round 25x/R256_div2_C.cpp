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

int calc(vi &v) {
    if (v.empty())return 0;
    int r = v[0];
    for (int x: v)r = min(r, x);

    vi t;
    int rst = v.size();
    int tmp = r;
    for (int x: v) {
        if (x == r) {
            tmp += calc(t);
            t.clear();
        } else t.pb(x - r);
    }
    return min(rst, tmp + calc(t));
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    cout << calc(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
