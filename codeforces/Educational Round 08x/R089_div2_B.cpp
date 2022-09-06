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
    int n, x, m;
    cin >> n >> x >> m;
    vector<pi> v(m);
    pi r = {x, x};
    for (auto &[a, b]: v) {
        cin >> a >> b;
        if (a <= r.F && r.F <= b)r.F = a;
        if (a <= r.S && r.S <= b)r.S = b;
    }
    cout << r.S - r.F + 1 << endl;
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
