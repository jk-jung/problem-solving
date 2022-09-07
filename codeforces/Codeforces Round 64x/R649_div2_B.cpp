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
    vi v(n), r;
    for (int &x: v)cin >> x;

    r.pb(v[0]);
    for (int i = 1; i < n; i++) {
        int x = v[i];
        if (r.size() >= 2) {
            int m = r.size();
            if (ab(r[m - 1] - r[m - 2]) + ab(r[m - 1] - x) == ab(r[m-2] - x))
                r.pop_back();
            r.pb(x);
        } else r.pb(x);
    }

    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
    cout << endl;
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
